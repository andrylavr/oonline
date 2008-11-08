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
#pragma once
#include <map>
#include <boost/signal.hpp>
#include "GlobalDefines.h"
#include "Module.h"
class Event;
class Entity;
class GameServer;
class DefaultEvents{
public:
 boost::signal<void(UINT64)>		EventTick; /*ticks since start up, occurs every tick*/	
 boost::signal<void(UINT64)>		EventSecond;  /* Occurs every second, based on ticks:Number of seconds cine start*/
 boost::signal<void(UINT64)>		EventMinute; // Occurs every minutes, based of 
 boost::signal<void(UINT64)>		EventFiveMinute; // every five minutes
 boost::signal<void(UINT64)>		EventHalfhour;
 boost::signal<void(UINT64)>		EventHour;
 boost::signal<void()>				EventBoot; // Occurs once after server has finished loading.
 boost::signal<void()>				EventShutdown; // Occurs when the server begins shutdown.
 boost::signal<void(SOCKADDR_IN *)>	EventConnect; //  pointer to a INETADDR , on CONNECTIOn
 boost::signal<void(SOCKADDR_IN *)>	EventDisconnect;//pointer to an INETADDR
 boost::signal<void(Entity *)>		EventSpawn; // When a new NPC spawns , Pointer to entity object
 boost::signal<void(Entity *) >		EventDespawn; // Same as above on despawn
 boost::signal<void(Entity *)>		EventPlayerSpawn; // same as above, Player appears
 boost::signal<void(Entity *)>		EventPlayerDespawn; // same as above, despawn
 boost::signal<void(Entity *,std::string *)>	EventChat; // On Chat
 boost::signal<void(std::string *) >EventCommand; // above
 boost::signal<void(std::string *) >EventUnhandledCommand; // above,only when the default command handler find nothing
 boost::signal<void(std::string *) >EventConsoleCommand;// above, when a command is entered on the console 
 boost::signal<void() >				EventRemoteAdminUnload; // Remote Administration has been unloaded. All hooks,etc have already been dropped,

 boost::signal<void(SOCKADDR_IN *) >	EventRemoteAdminConnect; // Someone connected to remote admin. LPARAM INetaddress. WPARAM will contain ifn o structure
 boost::signal<void(SOCKADDR_IN *) >	EventRemoteAdminDisconnect; // Someone disconnected
 boost::signal<void(Module *)>			EventLoadModule;
 boost::signal<void(Module *)>			EventUnloadModule;
 DefaultEvents() : EventLoadModule(),EventUnloadModule(),EventRemoteAdminConnect(),EventRemoteAdminDisconnect(),
					EventRemoteAdminUnload(),EventConsoleCommand(),EventUnhandledCommand(),EventCommand(),EventPlayerDespawn(),
					EventSpawn(),EventDespawn(),EventConnect(),EventDisconnect(),
					EventBoot(),EventShutdown(), EventTick(),EventSecond(),EventMinute(),EventFiveMinute(),EventHalfhour(),EventHour()
 {		}
	


};
class EventSystem
{
public:
	EventSystem(GameServer *server);
	~EventSystem(void);
	DefaultEvents DefaultEvents;
	GameServer *GetGameServer()
	{
		return m_server;
	}
protected:
	GameServer *m_server;	
};
