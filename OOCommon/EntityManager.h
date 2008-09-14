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
*/
#pragma once
#include "GlobalDefines.h"
#include "Packets.h"
#include "EntityUpdateManager.h"
#ifndef OO_USE_HASHMAP	//Slower and more secure 
#include <map>
#else
#endif
class Entity;
class EventSystem;
class NetworkSystem;
class IOStream;
typedef std::pair<UINT32,Entity *> IDEntityPair;
class EntityManager
{	
private:
#ifndef OO_USE_HASHMAP	
	std::map<UINT32,Entity *> m_objects; //Includes actors
	std::map<UINT32,Entity *> m_players;
#else
	OOHashTable m_objects
	OOHashTable m_players;

#endif
	IOStream *m_IO;
	EntityUpdateManager *m_updatemgr;
public:
	inline const std::map<UINT32,Entity *>& GetPlayerList() // TODO : evaluate if this is necessary
	{
		return m_players;
	}
	EntityManager(IOStream *io,NetworkSystem *netsys = NULL)
	{
		m_IO = io;
		m_updatemgr = new EntityUpdateManager(this,netsys);
	}
	EntityUpdateManager* GetUpdateMgr()
	{
		return m_updatemgr;
	}
	~EntityManager(void)
	{
		DeleteEntities();
	}
	bool RegisterEntity(Entity *Entity);
	bool DeleteEntity(Entity *Entity);
	bool DeRegisterEntity(Entity *Entity);
	bool DeleteEntities();
	inline Entity * GetEntity(BYTE Status,UINT32 RefID)
	{
		std::map<UINT32,Entity *>::iterator iter;
	if(Status == STATUS_PLAYER)
	{
		iter =  m_players.find(RefID);
		if(iter != m_players.end())
			return iter->second;
	}
	else
	{
		iter =  m_objects.find(RefID);
		if(iter != m_objects.end())
			return iter->second;
	}
	return NULL;
	}
};

