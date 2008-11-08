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
#if 0
#include <list>
#include "Event.h"
#include "EventSystem.h"

Event::Event(EventSystem *system,UINT32 Id) : globalcallbacks() , localcallbacks() lock()
{
	m_system = system;
	EventID = Id;
	system->RegisterEvent(this);
}
Event::~Event()
{
	 system->DeregisterEvent(this);
}
bool Event::RegisterCallback(EventCallback cb)
{
	lock->lock();
	globalcallbacks.push_back(cb);
	lock->unlock();
	return true;
}
bool Event::RegisterCallback(EventCallback cb, Entity *entity)
{
	std::map<Entity *,std::list<EventCallback>>::iterator current;
	lock->lock();
	current = localcallbacks.find(entity);
	if(current == localcallbacks.end()) // insert new table
	{
		localcallbacks.insert(entity,new std::list<EventCallback>());
		current = localcallbacks.find(entity);
		ASSERT(current != localcallbacks.end);
	}
	current->push_back(cb);
	lock->unlock();
	return true;
}
bool Event::Trigger(Entity *ent, void *wparam, void *lparam)
{
	try
	{
	std::map<Entity *,std::list<EventCallback>>::iterator current;	
	std::list<EventCallback>::iterator listiterator;
	lock->lock();
	current = localcallbacks.find(entity);
	if(current != localcallbacks.end())
	{
		listiterator = current->begin();
		while(listiterator != current->end())
		{
			(*listiterator)(this,ent,wparam,lparam);
		}
	}
	listiterator = globalcallbacks.begin();
	while(listiterator != current->end())
	{
		(*listiterator)(this,ent,wparam,lparam);
	}
	lock->unlock()
	return true;
	}catch(...)
		return false;//Not exactly great,but fast and stable. Remember we dump a few K events a second usually
}
#endif