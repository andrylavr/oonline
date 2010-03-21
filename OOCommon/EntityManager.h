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
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <boost/tr1/tr1/unordered_map>
#include "GlobalDefines.h"
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
OO_API class EntityManager
{	
protected:
	boost::mutex lock;
	std::map<UINT32,Entity *> m_entities;
	IOStream *m_IO;
	EntityUpdateManager *m_updatemgr;
public:
	const map<UINT32,Entity *>::const_iterator BeginObjects()
	{
		return m_entities.begin();
	}
	const map<UINT32,Entity *>::const_iterator EndObjects()
	{
		return m_entities.end();
	}
	EntityManager(IOStream *io) : lock() , m_entities()
	{
		m_IO = io;
	}
	void SetUpdateManager(EntityUpdateManager *mgr)
	{
		m_updatemgr = mgr;
	}
	EntityUpdateManager* GetUpdateMgr()
	{
		return m_updatemgr;
	}
	~EntityManager(void)
	{
		DeleteEntities();
	}
	IOStream & GetIO()
	{
		return *m_IO;
	}
	bool RegisterEntity(Entity *Entity);
	bool DeleteEntity(Entity *Entity);
	bool DeRegisterEntity(Entity *Entity);
	bool DeleteEntities();
	Entity * GetEntity(UINT32 RefID);
	// Gets You an Entity or creates it
	Entity * GetOrCreateEntity(UINT32 RefID);
};

