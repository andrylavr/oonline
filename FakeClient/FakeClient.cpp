/*

Copyright(c) 2007-2009   Julian Bangert aka masterfreek64

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
#include "InPacket.h"
#include "../OblivionOnlineServer/ScreenIOProvider.h"
#include "OutPacketStream.h"
#include "NetSend.h"
#include "EntityManager.h"
SOCKET ServerSocket;
bool g_plot = true;

OutPacketStream * outnet;
int TotalPlayers;
DWORD WINAPI RecvThread(LPVOID Params)
{
	char buf[PACKET_SIZE];
	int rc;
	InPacket * pkg;
	g_fake->GetIO() << "Receive thread started" <<endl;
	while(1)
	{
		rc = recv(ServerSocket,buf,PACKET_SIZE,0);
		if(rc == SOCKET_ERROR)
		{
			g_fake->GetIO() << "Server dropped connection.Press any key to quit" << endl;
			getc(stdin);
			exit(1);
		}
		pkg = new InPacket(g_fake->GetEntities(),&g_fake->GetIO(),(BYTE *)buf,rc);
		pkg->HandlePacket();
		delete pkg;
	}
	return 0;
}

FakeClient::FakeClient(void)
{
	IOSys = new IOSystem();
	IO = new IOStream(IOSys);
	//new LogIOProvider(IOSys,LogLevel::BootMessage,"OblivionOnline.log");
	IO->RegisterIOProvider(new ScreenIOProvider(IOSys,LogLevel::BootMessage));
	*IO << BootMessage << "Initializing game client: IO running" <<endl;
	Entities = new EntityManager(IO);
	Entities->SetUpdateManager(new FakeEntityUpdateManager(Entities,NULL));
	bIsConnected = false;
	bIsMasterClient = false;
	bIsInitialized = false;
}

FakeClient::~FakeClient(void)
{
	delete Entities;
	delete IO;
	delete IOSys;

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
	*IO << "OblivionOnline connecting" <<endl;
	*IO <<"Initializing GUI" <<endl;
	//InitialiseUI();
	bIsInitialized = false;
	//Entities->DeleteEntities();
	TotalPlayers = 0;
	LocalPlayer = -1;
	*IO <<		BootMessage << "OblivionOnline debug client"<<endl;
	*IO << BootMessage << "Trying to connect to "<< IP << " : " << ClientPort <<endl;
	memset(&ServerAddr,NULL,sizeof(SOCKADDR_IN));
	ServerAddr.sin_addr.s_addr = inet_addr(IP);
	ServerAddr.sin_port = htons(ClientPort);
	ServerAddr.sin_family = AF_INET;
	rc = connect(ServerSocket,(SOCKADDR *)&ServerAddr,sizeof(SOCKADDR));
	if(rc == SOCKET_ERROR)
	{
		*IO << Error << "Error" << WSAGetLastError() << " establishing connection " <<endl;
		return;
	}
	else 
	{
		*IO << "Successfully connected" << endl;

		outnet = new OutPacketStream(ServerSocket,ServerAddr,IO);

		//RecvThread(NULL);
		CreateThread(NULL,NULL,RecvThread,NULL,NULL,NULL);
		//hPredictionEngine = CreateThread(NULL,NULL,PredictionEngine,NULL,NULL,NULL);
		Sleep(100);
		*IO << BootMessage << "Waiting for Player ID" <<endl;
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
		UINT32 Interior;
		float f[6];
		UINT32	formID;
		BYTE	status;
	case 'p': //position
		sscanf(String,"p %f %f %f %f %f %f ",f,f+1,f+2,f+3,f+4,f+5);
		NetSendPosition(outnet,LocalPlayer,STATUS_PLAYER,f[0],f[1],f[2],f[3],f[4],f[5]);
		outnet->Send();
		break;
	case 'P': //position of another item
		sscanf(String,"P %U %u %f %f %f %f %f %f",&formID,&status,f,f+1,f+2,f+3,f+4,f+5);
		NetSendPosition(outnet,LocalPlayer,STATUS_PLAYER,f[0],f[1],f[2],f[3],f[4],f[5]);
		outnet->Send();
		break;
	case 'c': //cell
		sscanf(String,"c %u %u",&CellID,&Interior);
		NetSendCellID(outnet,LocalPlayer,STATUS_PLAYER,CellID,Interior);
		outnet->Send();
		break;
	case 'a': // Actor Value
		sscanf(String,"a %u %d",&CellID,&Interior);
		NetSendActorValue(outnet,LocalPlayer,STATUS_PLAYER,CellID,Interior);
		outnet->Send();
		break;
	case 'e': // Actor Value
		sscanf(String,"e %u %d",&CellID,&Interior);
		NetSendEquip(outnet,LocalPlayer,STATUS_PLAYER,CellID,Interior);
		outnet->Send();
		break;
	
	}
}
FakeClient *g_fake;
void main()
{
	g_fake = new FakeClient();
	g_fake->run();
	delete g_fake;
}