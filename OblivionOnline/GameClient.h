#pragma once
#include <deque>
#include <iostream>
#include "IOSystem.h"
#include "EntityManager.h"

class GameClient
{
private:
	std::deque<Entity *> UpdateQueue;
	// Prototypes
	IOSystem *IOSys;
	IOStream *IO;
	EntityManager *Entities;
	bool bIsConnected; //TCP / IP connection exists
	bool bIsMasterClient; // We have "write rigths" to the server entities
	bool bIsInitialized; // We received a player ID
	bool bPlayersConnected[MAXCLIENTS];
	UINT32 LocalPlayer;
	UINT32 TotalPlayers;

	HANDLE hRecvThread;
	SOCKET ServerSocket;

	UInt32 SpawnID[MAXCLIENTS];

	char ServerIP[15];
public:
	GameClient(void);
	~GameClient(void);
	int Initialize();
	int Deinitialize();
	bool Connect();
	bool Disconnect();
	IOStream &GetIO() 
	{
		return *IO;
	}
	EntityManager *GetEntities()
	{
		return Entities;
	}
	UINT32 GetTotalPlayers()
	{
		return TotalPlayers;
	}
	UINT32 GetLocalPlayer()
	{
		return LocalPlayer;
	}
	bool GetIsConnected()
	{
		return bIsConnected;
	}
	bool GetIsInitialized()
	{
		return bIsInitialized;
	}
	bool GetIsMasterClient()
	{
		return bIsMasterClient;
	}
	bool GetIsPlayerConnected(UINT32 ID)
	{
		return bPlayersConnected[ID];
	}
	std::deque<Entity *> *GetUpdateQueue()
	{
		return &UpdateQueue;
	}
	void SetPlayerID(UINT32 Value)
	{
		LocalPlayer = Value;
		bIsInitialized = true;
	}
	void SetIsMasterClient(bool Value)
	{
		bIsMasterClient = Value;
	}
	SOCKET &GetSocket()
	{
		return ServerSocket;
	}
	UINT32 GetSpawnID(UINT32 PlayerID)
	{
		return SpawnID[PlayerID];
	}
	void SetSpawnID(UINT32 PlayerID,UINT32 Value)
	{
		SpawnID[PlayerID] = Value;
	}
};

