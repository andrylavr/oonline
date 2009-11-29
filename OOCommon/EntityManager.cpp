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
#include "EntityManager.h"
#include "Entity.h"
#include "IOSystem.h"
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/bind.hpp"
#include "boost/lambda/if.hpp"
bool EntityManager::RegisterEntity(Entity *Entity)
{
	lock.lock();
	//(*m_IO)<<SystemMessage<<"Spawning Entity "<<Entity->RefID()<<endl;
#ifndef OO_USE_HASHMAP
	if(Entity->Status() == STATUS_PLAYER)
		m_players.insert(IDEntityPair(Entity->RefID(),Entity));
	else
		m_objects.insert(IDEntityPair(Entity->RefID(),Entity));
#else
	if(Entity->Status())
		m_players.Insert(Entity);
	else
		m_objects.Insert(Entity);
#endif	
	lock.unlock();
	return true;
}
bool EntityManager::DeleteEntity(Entity *Entity)
{
	delete Entity;
	return true;
}
bool EntityManager::DeleteEntities()
{
	#ifndef OO_USE_HASHMAP
	lock.lock();
	for(std::map<UINT32,Entity *>::iterator i = m_objects.begin();i != m_objects.end();i++)
	{
		delete i->second;
	}
	m_objects.clear();
	for(std::map<UINT32,Entity *>::iterator i = m_players.begin();i != m_players.end();i++)
	{
		delete i->second;
	}
	m_players.clear();
	lock.unlock();
	#else
	// TODO
	printf("SOMEBODY TOLD YOU NOT TO MESS WITH DEVELOPMENT CODE !!! BETTER LISTEN");
	#endif	
	return true;
}
bool EntityManager::DeRegisterEntity(Entity *Entity)
{
	lock.lock();
#ifndef OO_USE_HASHMAP
	if(Entity->Status())
		m_players.erase(Entity->RefID());
	else
		m_objects.erase(Entity->RefID());
#else
	if(Entity->Status())
		m_players.Remove(Entity);
	else
		m_objects.Remove(Entity);
#endif	
	lock.lock();
	return true;	
}

Entity * EntityManager::GetEntity( BYTE Status,UINT32 RefID )
{
	std::map<UINT32,Entity *>::iterator iter;
	if(Status == STATUS_PLAYER)
	{
		for(iter = m_players.begin();iter!=m_players.end();iter ++)
		{
			if(iter->first == RefID)
				return iter->second;
		}
	}
	else
	{
		iter =  m_objects.find(RefID);
		if(iter != m_objects.end())
			return iter->second;
	}
	return NULL;
}

Entity *EntityManager::GetOrCreateEntity( BYTE Status,UINT32 RefID )
{
	Entity * retval = GetEntity(Status,RefID);
	if(!retval)
	{
		retval = CreateEntity(Status,RefID);
		if(!retval)
			throw "Out of Memory";
	}
	return retval;
}

Entity * EntityManager::CreateEntity( BYTE Status,UINT32 RefID )
{
	return new Entity(this,RefID,Status);
}