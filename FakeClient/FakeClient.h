#pragma once
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
#include <string>
extern bool g_plot;
#include "GlobalDefines.h"
#include "EntityUpdateManager.h"

class EntityManager;

class FakeClient
{
private:	
			EntityManager *Entities;
			bool bIsConnected; //TCP / IP connection exists
			bool bIsMasterClient; // We have "write rigths" to the server entities
			bool bIsInitialized; // We received a player ID
			UINT32 LocalPlayer;
public:
	FakeClient(void);
	~FakeClient(void);
	void SetIsMasterClient(bool Value) {bIsMasterClient = Value;}
	void SetPlayerID(UINT32 value);
	EntityManager *GetEntities() {return Entities;}
	void run();
	void HandleCommand(char * String);
};
class FakeEntityUpdateManager : public EntityUpdateManager
{
public:
	FakeEntityUpdateManager(EntityManager *mgr,NetworkSystem *netsys) : EntityUpdateManager(mgr)
	{

	}
	OO_API virtual void OnAVModUpdate(Entity *ent,unsigned char AVCode,bool Inbound);
	OO_API virtual void OnPositionUpdate(Entity *ent,bool Inbound );//Triggers Events and network code;
	OO_API virtual void OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound );
	OO_API virtual  void GlobalSend(Entity *ent,bool Inbound );
	OO_API virtual void OnNameUpdate(Entity *ent,bool Inbound );
	OO_API virtual void OnEquipUdate(Entity *ent,unsigned char slot,bool Inbound );
	OO_API virtual void OnClassUpdate(Entity *ent,bool Inbound );
	OO_API virtual void OnCellChange(Entity *ent,UINT32 oldCell, bool Inbound );
	OO_API virtual void OnRaceUpdate(Entity *ent,bool Inbound );
	OO_API virtual void OnAnimationUpdate(Entity *ent,bool Inbound );
	OO_API virtual void Chat(Entity *ent,std::string Message,bool Inbound );
	virtual bool NewPlayerID(UINT32 ID);
	virtual void NewClientStatus(bool IsMasterClient);
};
extern FakeClient *g_fake;