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
	
		m_entities.insert(IDEntityPair(Entity->RefID(),Entity));
#else
		m_entities.Insert(Entity);
#endif	
	lock.unlock();
	return true;
}
bool EntityManager::DeleteEntities()
{
	#ifndef OO_USE_HASHMAP
	lock.lock();
	for(std::map<UINT32,Entity *>::iterator i = m_entities.begin();i != m_entities.end();i++)
	{
		delete i->second;
	}
	m_entities.clear();
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
	m_entities.erase(Entity->RefID());
	lock.unlock();
	return true;	
}

Entity * EntityManager::GetEntity(UINT32 RefID )
{
	std::map<UINT32,Entity *>::iterator iter =  m_entities.find(RefID);
		if(iter != m_entities.end())
			return iter->second;

	return NULL;
}

Entity *EntityManager::GetOrCreateEntity(UINT32 RefID )
{
	Entity * retval = GetEntity(RefID);
	if(!retval)
	{
		retval = CreateEntity(RefID);
		if(!retval)
			throw std::runtime_error("Out of Memory");
	}
	return retval;
}

Entity * EntityManager::CreateEntity( UINT32 RefID )
{
	return new Entity(this,RefID);
}