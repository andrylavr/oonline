/*

Copyright(c) 2007-2010   Julian Bangert 

This file is part of OblivionOnline.

OblivionOnline is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

OblivionOnline is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

*/
#include <cstdlib>
#include "GlobalDefines.h"
#include "FakeClient.h"
#include "IOSystem.h"
#include "LogIOProvider.h"
#include "../OblivionOnlineServer/ScreenIOProvider.h"
#include "EntityManager.h"
#include "NetworkConnection.h"
SOCKET ServerSocket;
bool g_plot = true;

NetworkConnection *conn;
int TotalPlayers;
Entity *myself = NULL;
FakeClient *g_fake;
void Drop(NetworkConnection *netconn)
{
	IOStream::Instance() << FatalError << "Client dropped" <<endl;
	exit(-1);
}
void Receive()
{
	while(1)
	{
		conn->Process();
	}
}
FakeClient::FakeClient(void)
{
	//new LogIOProvider(&IOSystem::Instance(),LogLevel::BootMessage,"OblivionOnline.log");
	IOSystem::Instance().RegisterIOProvider(new ScreenIOProvider(&IOSystem::Instance(),LogLevel::BootMessage));
	IOStream::Instance() << BootMessage << "Initializing game client: IO running" <<endl;
	Entities = new EntityManager(&IOStream::Instance());
	Entities->SetUpdateManager(new FakeEntityUpdateManager(Entities,NULL));
	bIsConnected = false;
	bIsMasterClient = false;
	bIsInitialized = false;
}

FakeClient::~FakeClient(void)
{
	delete Entities;
}
void FakeClient::run()
{
	long rc;
	WSADATA wsa;
	SOCKADDR_IN ServerAddr;
	char IP[15]= "127.0.0.1";
	unsigned short ClientPort = 41805;
	rc = WSAStartup(MAKEWORD(2,0),&wsa);
	ServerSocket = socket(AF_INET,SOCK_STREAM,0);
	IOStream::Instance() << "OblivionOnline connecting" <<endl;
	bIsInitialized = false;
	//Entities->DeleteEntities();
	TotalPlayers = 0;
	LocalPlayer = -1;
	IOStream::Instance() <<		BootMessage << "OblivionOnline debug client"<<endl;
	IOStream::Instance() << BootMessage << "Trying to connect to "<< IP << " : " << ClientPort <<endl;
	memset(&ServerAddr,NULL,sizeof(SOCKADDR_IN));
	ServerAddr.sin_addr.s_addr = inet_addr(IP);
	ServerAddr.sin_port = htons(ClientPort);
	ServerAddr.sin_family = AF_INET;
	rc = connect(ServerSocket,(SOCKADDR *)&ServerAddr,sizeof(SOCKADDR));
	if(rc == SOCKET_ERROR)
	{
		IOStream::Instance() << Error << "Error" << WSAGetLastError() << " establishing connection " <<endl;
		return;
	}
	else 
	{
		IOStream::Instance() << "Successfully connected" << endl;

		ChunkPermissions cp_any(MATCH_ALL);
		conn=new NetworkConnection(Entities,ServerSocket,Drop,cp_any);
		boost::thread recvthread(Receive);
		Sleep(100);
		IOStream::Instance() << BootMessage << "Waiting for Player ID" <<endl;
		bIsConnected = true;
		while(1)
		{
			char cmd[2048];
			fgets(cmd,2047,stdin);
			HandleCommand(cmd);
		}
	}
}
void FakeClient::HandleCommand(char *String)
{
	switch(String[0])
	{
		UINT32 CellID;
		UINT32 Integer;
		int AV;
		float f[6];
		UINT32	formID;
	case 'p': //position
		sscanf(String,"p %f %f %f %f %f %f ",f,f+1,f+2,f+3,f+4,f+5);
		myself->MoveNRot(f[0],f[1],f[2],f[3],f[4],f[5]);
		conn->Process();
		break;
	case 'P': //position of another item
		sscanf(String,"P %U %f %f %f %f %f %f",&formID,f,f+1,f+2,f+3,f+4,f+5);
		g_fake->GetEntities()->GetOrCreateEntity(formID)->MoveNRot(f[0],f[1],f[2],f[3],f[4],f[5]);
		conn->Process();
		break;
	case 'c': //cell
		sscanf(String,"c %u %u",&CellID,&Integer);
		myself->SetCell(CellID,Integer);
		conn->Process();
		break;
	case 'n': // Animation
		sscanf(String,"n %u ",&CellID);
		myself->SetAnimation(CellID);
		conn->Process();
		break;
	case 'a': // Actor Value
		sscanf(String,"a %u %d",&CellID,&AV);
		myself->SetActorValue(CellID,AV);
		conn->Process();
		break;
	case 'e': // Actor Value
		sscanf(String,"e %u %d",&CellID,&Integer);
		myself->SetEquip(CellID,Integer);
		conn->Process();
		break;
	
	}
}

void FakeClient::SetPlayerID( UINT32 value )
{
//	if(myself) delete myself;
	myself =g_fake->GetEntities()->GetOrCreateEntity(value);
}
void main()
{
	Sleep(2000);//Debugging
	g_fake = new FakeClient();
	g_fake->run();
	delete g_fake;
}

bool FakeEntityUpdateManager::NewPlayerID( UINT32 ID )
{
	g_fake->SetPlayerID(ID);
	return true;
}

void FakeEntityUpdateManager::NewClientStatus( bool IsMasterClient )
{
	if(IsMasterClient)
		IOStream::Instance() << GameMessage << "Received Master Client!"<<endl;
	else
		IOStream::Instance() << GameMessage<<"Received Passive Client!"<<endl;
}