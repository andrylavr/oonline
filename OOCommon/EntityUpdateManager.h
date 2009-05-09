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
class NetworkSystem;
class Entity;
class EntityManager;
class GameServer;
#include <string>
// The implementation is  different on client and server */
OO_API class EntityUpdateManager
{
private:
	EntityManager *m_mgr;
	NetworkSystem *m_net;
public:
	EntityUpdateManager(EntityManager *mgr,NetworkSystem *netsys)
	{
		m_mgr = mgr;
		m_net = netsys;
	};
	NetworkSystem *GetNetsys()
	{
		return m_net;
	}
	OO_API void OnPositionUpdate(Entity *ent,bool Inbound );//Triggers Events and network code;
	OO_API void OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound );
	OO_API void GlobalSend(Entity *ent,bool Inbound );
	OO_API void OnNameUpdate(Entity *ent,bool Inbound );
	OO_API void OnEquipUdate(Entity *ent,unsigned char slot,bool Inbound );
	OO_API void OnClassUpdate(Entity *ent,bool Inbound );
	OO_API void OnCellChange(Entity *ent,bool Inbound );
	OO_API void OnRaceUpdate(Entity *ent,bool Inbound );
	OO_API void OnGenderUpdate(Entity *ent,bool Inbound );
	OO_API void OnAnimationUpdate(Entity *ent,unsigned char AnimationID,bool Inbound );
	OO_API void Chat(Entity *ent,std::string Message,bool Inbound );
};