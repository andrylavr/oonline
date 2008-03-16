/*
OblivionOnline Server- An open source game server for the OblivionOnline mod
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
#pragma once
#include <list>
#include "../OblivionOnlineServer/GlobalDefines.h"
class EventSystem;
class Event;
typedef void (*EventCallback)(Event *Event,void * wparam,void * lparam);
class Event
{
public:
	Event(EventSystem *system);
	~Event(void);
	UINT32 EventID;
	bool RegisterCallback(EventCallback cb);
	bool UnregisterCallback (EventCallback cb);
	bool Trigger(void *wparam,void *lparam);
protected:
	std::list <EventCallback> callbacks;	
};
