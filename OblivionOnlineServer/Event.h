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
#pragma once
#include <list>
#include <map>
#include "GlobalDefines.h"
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
typedef void (*EventCallback)(Event *Event,Entity *ent,void * wparam,void * lparam);
class Event
{
public:
	Event(EventSystem *system,UINT32 Id);
	~Event(void);
	bool RegisterCallback(EventCallback cb);
	bool RegisterCallback(EventCallback cb,Entity *entity);
	bool UnregisterCallback (EventCallback cb);
	bool Trigger(Entity *ent,void *wparam,void *lparam);
	UINT32 GetID(){ return EventID; }
protected:
	std::list <EventCallback> globalcallbacks;
	std::map<Entity *,std::list<EventCallback>> localcallbacks; // Map is bad. Maybe make a tasklist for simulataneous event handling
private:	
	boost::mutex lock;
	UINT32 EventID;
	EventSystem *m_system;
};
#endif 