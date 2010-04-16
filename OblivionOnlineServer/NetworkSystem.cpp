/*
This file is part of OblivionOnline Server- An open source game server for the OblivionOnline mod
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
*/
#include "NetworkSystem.h"
#include "GameServer.h"
#include "LuaSystem.h"
#include "EventSystem.h"
#include "NetworkConnection.h"
#include <sstream>
#include "Entity.h"
#include "TaskHandler.h"
#include "PlayerManager.h"
#ifdef WIN32
#include <process.h>
#include <Windows.h>
#else
#include <pthread.h>
#endif
using namespace boost;
NetworkSystem::~NetworkSystem(void)
{
}
NetworkSystem::NetworkSystem( GameServer *Server ) :m_GS(Server), _work(false),_work_notify(),_listlock(), 
	_tcp(boost::bind<void>(&NetworkSystem::AcceptThread,ref(*this))),
	_playerdefault(MATCH_NONE)
{
}
void NetworkSystem::AcceptThread() // Run accept and listen on a TCP socket
{
	{
		boost::unique_lock<boost::mutex> guard(_listlock);
		while(!_work)
			_work_notify.wait(guard);
	}
#ifdef WIN32
	WSADATA wsad;
	WSAStartup(MAKEWORD(2,2),&wsad);
#endif
	unsigned short port = m_GS->GetLua()->GetInteger("ServicePort");
	SOCKET acceptSocket = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addr;
	long rc;
	memset(&addr,0,sizeof(SOCKADDR_IN));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr=INADDR_ANY;
	rc = ::bind(acceptSocket,(SOCKADDR*)&addr,sizeof(SOCKADDR_IN));
	if( rc == SOCKET_ERROR)
	{
		IOStream::Instance()<<FatalError<<"Couldn't bind TCP"<< endl;
	}
	else
	{
		IOStream::Instance()<<BootMessage<<"TCP Bound to port " << port <<endl;
	}
	rc = listen(acceptSocket,4);
	if(rc == SOCKET_ERROR)
	{
		IOStream::Instance()<<FatalError<<"Couldn't listen on TCP"<<endl;
	}
	else
	{
		IOStream::Instance()<<BootMessage<<"TCP listening"<<endl;
	}
	while(1)
	{
			SOCKADDR_IN remoteaddr;
			int addr_size;
			addr_size = sizeof(SOCKADDR_IN);			
			SOCKET sock = accept(acceptSocket,(SOCKADDR *)&addr,&addr_size);
			try
			{
				IOStream::Instance() << GameMessage << "New game connection from "<< inet_ntoa(addr.sin_addr) <<endl;
				AddPlayer(sock);
			}
			catch (std::exception e)
			{
				if(e.what())
					IOStream::Instance()<<Error<<"Exception encountered opening connection: "<< e.what() <<endl;
				else 
					IOStream::Instance()<<Error<<"Exception encountered opening connection: "<<endl;
			}
			catch(...)
			{
			}
	}
}
void NetworkSystem::AddPlayer( SOCKET sock )
{
	boost::lock_guard<boost::mutex> guard(_listlock);
	NetworkConnection *net = m_GS->GetPlayerManager()->GetPlayer(sock);
	_connections.insert(net);
	boost::function0<bool> callback = boost::bind(&NetworkConnection::Process,ref(*net));
	TaskHandler::Instance().ScheduleLoop(callback,m_GS->GetLua()->GetInteger("TickRate"));
}
void NetworkSystem::OnDisconnect( NetworkConnection *ptr )
{
	boost::lock_guard<boost::mutex> guard(_listlock);
	_connections.erase(ptr);
	//delete ptr; // the calling function only returns false.
}

/*
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
#ifndef WIN32 
	socklen_t inaddr_len;
#else		  
	int inaddr_len;
#endif	
	inaddr_len = sizeof(SOCKADDR_IN);
	listenaddr.sin_family = AF_INET;
	listenaddr.sin_port = htons(port);
	listenaddr.sin_addr.s_addr = INADDR_ANY;
	if(bind(sock,(SOCKADDR *)&listenaddr,sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		netsys->GetGS()->GetIO()<<Error<<"Could not bind UDP"<<endl;
		#ifdef WIN32 
		return;
		#else 
		return NULL;
		#endif
	}
	else
		netsys->GetGS()->GetIO()<<BootMessage<<"UDP Bound to port "<<port <<endl;
       	PacketBuffer = (BYTE*) malloc(PACKET_SIZE);	
	while(1)//TODO : Add some sort of break
	{
		//PacketBuffer = (BYTE*) malloc (PACKET_SIZE); //TODO : Free these!!!
		size = recvfrom(sock,(char *)PacketBuffer,PACKET_SIZE,0,(SOCKADDR *)&inaddr,&inaddr_len);
		if(size != 0)
		{
			Player = netsys->GetPlayerFromAddr(inaddr);
			if(Player != -1)
				netsys->RegisterTraffic(netsys->GetPlayerFromAddr(inaddr),size,PacketBuffer,false);
			else
				netsys->GetGS()->GetIO()<<Warning<<"Unknown player sent data to UDP "<<endl;
			//free(PacketBuffer);
		}
	}
	free(PacketBuffer);
}

*/