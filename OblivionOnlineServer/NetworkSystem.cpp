/*
OblivionOnline Server- An open source game server for the OblivionOnline mod
Copyright (C)  2008   Julian Bangert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.


You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/#include "NetworkSystem.h"
#include "InPacket.h"
#include "GameServer.h"
#include "LuaSystem.h"
#include <sstream>
#ifdef WIN32
#include <process.h>
#include <Windows.h>
#else
#include <pthread.h>
#endif
NetworkSystem::~NetworkSystem(void)
{
}
bool NetworkSystem::StartReceiveThreads()
{
	m_GS->GetIO()<<BootMessage<<"Starting receive threads"<< endl;
#ifdef WIN32
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)TCPProc,(LPVOID) this,0,(LPDWORD)&m_TCPThread);
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)UDPProc,(LPVOID) this,0,(LPDWORD)&m_TCPThread);
#endif
	m_MasterClient = 0;
	return true;
}
OO_TPROC_RET NetworkSystem::TCPProc(void* _netsys)
{
	BYTE data[PACKET_SIZE];
	NetworkSystem *netsys = (NetworkSystem *) _netsys;
	unsigned short port = (unsigned short) netsys->GetGS()->GetLua()->GetInteger("ServicePort");
	SOCKET acceptSocket = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addr;
	FD_SET fdSet;
	long rc;
	memset(&addr,0,sizeof(SOCKADDR_IN));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr=INADDR_ANY;
	rc = bind(acceptSocket,(SOCKADDR*)&addr,sizeof(SOCKADDR_IN));
	if( rc == SOCKET_ERROR)
	{
		netsys->GetGS()->GetIO()<<FatalError<<"Couldn't bind TCP"<< endl;
		return ;
	}
	else
	{
		netsys->GetGS()->GetIO()<<BootMessage<<"TCP Bound to port" << port <<endl;
	}
	rc = listen(acceptSocket,4)==SOCKET_ERROR;
	if(rc == SOCKET_ERROR)
	{

		netsys->GetGS()->GetIO()<<FatalError<<"Couldn't listen on TCP"<<endl;
		return ;
	}
	else
	{

		netsys->GetGS()->GetIO()<<BootMessage<<"TCP listening"<<endl;
	}
	while(1)
	{
		FD_ZERO(&fdSet);
		FD_SET(acceptSocket,&fdSet);
		for(std::map<UINT,SOCKET>::iterator i = netsys->m_TCPSockets.begin();i!=netsys->m_TCPSockets.end();i++)
		{
			FD_SET(i->second,&fdSet);
		}
		if(select(0,&fdSet,NULL,NULL,NULL) == SOCKET_ERROR)
		{
			netsys->GetGS()->GetIO()<<FatalError<<"Error calling select()"<<endl;
			return;
		}
		if(FD_ISSET(acceptSocket,&fdSet))
		{
			SOCKADDR_IN addr;
			int addr_size = sizeof(SOCKADDR_IN);			
			SOCKET sock = accept(acceptSocket,(SOCKADDR *)&addr,&addr_size);
			netsys->AddNewPlayer(addr,sock);
		}
		for(std::map<UINT,SOCKET>::iterator i = netsys->m_TCPSockets.begin();i!= netsys->m_TCPSockets.end();i++)
		{
			if(FD_ISSET(i->second,&fdSet))
			{
				rc = recv(i->second,(char *)data,PACKET_SIZE,0);
				if(rc==0 || rc==SOCKET_ERROR)
				{
					//TODO: Handle player disconnect
				}
				else
				{
					netsys->RegisterTraffic(i->first,rc,data,true);
				}
			}
		}
	}
}
 OO_TPROC_RET NetworkSystem::UDPProc(void *thisptr)
{
	SOCKADDR_IN listenaddr;
	SOCKADDR_IN inaddr;
	UINT32 Player;
	BYTE *PacketBuffer;
	NetworkSystem *netsys = (NetworkSystem *) thisptr;
	SOCKET sock = socket(AF_INET,SOCK_DGRAM,0);
	unsigned short port = (unsigned short) netsys->GetGS()->GetLua()->GetInteger("ServicePort");
	size_t size;
	int inaddr_len = sizeof(SOCKADDR_IN);
	listenaddr.sin_family = AF_INET;
	listenaddr.sin_port = htons(port);
	listenaddr.sin_addr.S_un.S_addr = INADDR_ANY;
	if(bind(sock,(SOCKADDR *)&listenaddr,sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		netsys->GetGS()->GetIO()<<Error<<"Could not bind UDP"<<endl;
		return;
	}
	else
		netsys->GetGS()->GetIO()<<BootMessage<<"UDP Bound to port "<<port <<endl;
	
	while(1)//TODO : Add some sort of break
	{
		PacketBuffer = (BYTE*) malloc (PACKET_SIZE); //TODO : Free these!!!
		size = recvfrom(sock,(char *)PacketBuffer,PACKET_SIZE,0,(SOCKADDR *)&inaddr,&inaddr_len);
		Player = netsys->GetPlayerFromAddr(inaddr);
		if(Player != 0)
			netsys->RegisterTraffic(netsys->GetPlayerFromAddr(inaddr),size,PacketBuffer,false);
		else
			netsys->GetGS()->GetIO()<<Warning<<"Unknown player sent data to UDP "<<endl;
		free(PacketBuffer);
	}
}

 bool NetworkSystem::RegisterTraffic( UINT32 PlayerID,size_t size,BYTE *data,bool reliable )
 {
	if(!reliable && !ValidatePacketLength(data,size))
	{
		m_GS->GetIO()<<Warning<<"Found Packet with wrong size - ignoring"<<endl;
		return false;
	}
	InPacket *pkg = new InPacket(this,m_GS,data,size);
	pkg->HandlePacket();
	return true;
 } 

 UINT32 NetworkSystem::AddNewPlayer( SOCKADDR_IN addr,SOCKET TCPSock )
 {
	BYTE masterclient;
	 UINT32 ID = 0;
	 std::map<UINT32,SOCKADDR_IN>::iterator iter;
	 //Find a new RefID
	 for(iter = m_PlayerAddresses.begin();iter != m_PlayerAddresses.end();iter++)
	 {
		  if(++ID != iter->first)
			  break;
	 }
	 if(iter == m_PlayerAddresses.end())
		 ID++;

	 m_PlayerAddresses[ID] = addr;
	 m_AddressPlayer[addr.sin_addr.S_un.S_addr] = ID;
	 m_OutPackets[ID] = new OutPacket(ID);
	 m_GS->GetIO()<<GameMessage<< "New player" << ID << "joined from address"<< inet_ntoa(addr.sin_addr) << ":" <<ntohs(addr.sin_port)<<endl;
	 if(m_MasterClient == 0)
	 {
		 masterclient = 1;
		 m_MasterClient = ID;
		 m_GS->GetIO()<<GameMessage<<"Selected new master client"<<ID<<endl;
		 m_OutPackets[ID]->AddChunk(ID,STATUS_PLAYER,GetMinChunkSize(ClientType),ClientType,(BYTE *)&masterclient);
	 }
	 return ID;
}

NetworkSystem::NetworkSystem( GameServer *Server )
{
	m_GS = Server;
#ifdef WIN32
	WSADATA wsad;
	WSAStartup(MAKEWORD(2,2),&wsad);
#endif
	m_TCPSockets.clear();
	m_UDPSock = socket(AF_INET,SOCK_DGRAM,0);
}

bool NetworkSystem::SendReliableStream( UINT32 PlayerID,size_t length,BYTE *data )
{
	send(m_TCPSockets.find(PlayerID)->second,(const char *)data,length,0);
	return true;
}
bool NetworkSystem::SendUnreliableStream( UINT32 PlayerID,size_t length,BYTE *data )
{
	sendto(m_UDPSock,(const char *)data,length,0,(SOCKADDR *)&m_PlayerAddresses.find(PlayerID)->second,sizeof(SOCKADDR_IN));
	return true;
}

bool NetworkSystem::PlayerDisconnect( UINT32 ID )
{
	BYTE masterclient = 1;
	m_GS->GetIO()<<GameMessage<<"Client "<<ID<< "disconnected" <<endl;
	m_AddressPlayer.erase(m_PlayerAddresses[ID].sin_addr.S_un.S_addr);
	m_PlayerAddresses.erase(ID);
	delete m_OutPackets[ID];
	m_OutPackets.erase(ID);
	m_GS->GetIO()<<GameMessage<<"We now have"<<GetPlayerCount()<< "players" <<endl;
	if(m_MasterClient == ID)
	{
		if(GetPlayerCount() > 0) // We have already reduced it
		{
			m_MasterClient = m_OutPackets.begin()->first;
			m_OutPackets.begin()->second->AddChunk(m_MasterClient,true,GetMinChunkSize(ClientType),ClientType,&masterclient);
			m_GS->GetIO()<<GameMessage<<"Selected new master client"<<m_MasterClient<<endl;
		}
		else
		{
			m_MasterClient = 0;
		}
	}
	return true;
}