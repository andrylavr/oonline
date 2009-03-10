#include "main.h"
#include "GameClient.h"
#include "LogIOProvider.h"
#include "UserInterface.h"
#include "OutPacketStream.h"
GameClient::GameClient(void) : UpdateQueue()
{
	/*
	1 IO
	2 Network
	3 Entity
	*/
	IOSys = new IOSystem();
	IO = new IOStream(IOSys);
	IOSys->RegisterIOProvider(new LogIOProvider(IOSys,LogLevel::BootMessage,"OblivionOnline.log"));
	*IO << BootMessage << "Initializing game client: IO running" <<endl;
	Entities = new EntityManager(IO);
	bIsConnected = false;
	bIsMasterClient = false;
	bIsInitialized = false;
}

GameClient::~GameClient(void)
{
	delete Entities;
	delete IO;
	delete IOSys;
}

int GameClient::Initialize()
{
	long rc;
	WSADATA wsa;
	rc = WSAStartup(MAKEWORD(2,0),&wsa);
	ServerSocket = socket(AF_INET,SOCK_STREAM,0);
	*IO << "OblivionOnline connecting" <<endl;
	*IO <<"Initializing GUI" <<endl;
	//InitialiseUI();
	bIsInitialized = false;
	//Entities->DeleteEntities();
	TotalPlayers = 0;
	LocalPlayer = MAXCLIENTS;
	for(int i=0; i<MAXCLIENTS; i++)
	{
		bPlayersConnected[i] = false;
		SetSpawnID(i,0);
	}
	return rc;
}

int GameClient::Deinitialize()
{
	for(int i=0; i<MAXCLIENTS; i++)
	{
		bPlayersConnected[i] = false;
	}
	bIsInitialized = false;
	TotalPlayers = 0;
	TerminateThread(hRecvThread, 0);
	CloseHandle(hRecvThread);
	gClient->GetEntities()->DeleteEntities();
	closesocket(ServerSocket);
	ServerSocket = INVALID_SOCKET;
	WSACleanup();
	DeinitialiseUI();
	//D3DHookDeInit();

	return 1;
}

bool GameClient::Connect()
{

	char IP[15] = "";
	SOCKADDR_IN ServerAddr;
	unsigned short ClientPort = 41805;
	long rc = 0;
	if(!bIsConnected)
	{
		*IO << BootMessage << "Initializing Connection" <<endl; 
		Initialize();

		FILE *Realmlist = fopen("realmlist.wth","r");
		if(!Realmlist)
		{
			*IO << Error << "File realmlist.wth could not be found" << endl;
			return false;
		}
		while(!feof(Realmlist))
		{
			fscanf(Realmlist,"%14s",IP);
			if(!fscanf(Realmlist,"%i",&ClientPort))
				ClientPort = 41805;
			*IO << BootMessage << "Trying to connect to "<<IP << " : "<<ClientPort <<endl;
			memset(&ServerAddr,NULL,sizeof(SOCKADDR_IN));
			ServerAddr.sin_addr.s_addr = inet_addr(IP);
			ServerAddr.sin_port = htons(ClientPort);
			ServerAddr.sin_family = AF_INET;
			rc = connect(ServerSocket,(SOCKADDR *)&ServerAddr,sizeof(SOCKADDR));
			if(rc == SOCKET_ERROR)
			{
				*IO << "Error" << WSAGetLastError() << " establishing connection " <<endl;
				continue;
			}
			else 
			{
				*IO << "Successfully connected" << endl;
				
				outnet = new OutPacketStream(GetSocket(),ServerAddr,IO);
				

				hRecvThread = CreateThread(NULL,NULL,RecvThread,NULL,NULL,NULL);
				//hPredictionEngine = CreateThread(NULL,NULL,PredictionEngine,NULL,NULL,NULL);
				*IO << BootMessage << "Waiting for Player ID" <<endl;
				bIsConnected = true;
				break;
			}
		}
		fclose(Realmlist);
	}
	return true;
}

bool GameClient::Disconnect()
{
	if(bIsConnected)
	{
		Deinitialize();
		bIsConnected = false;
		*IO << BootMessage << "Successfully disconnect" << endl;
	}else{
		*IO << BootMessage << " You are not connected" << endl;
	}
	return true;
}