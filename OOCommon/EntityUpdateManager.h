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
class EntityUpdateManager
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
	void OnPositionUpdate(Entity *ent,bool Inbound );//Triggers Events and network code;
	void OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound );
	void GlobalSend(Entity *ent,bool Inbound );
	void OnNameUpdate(Entity *ent,bool Inbound );
	void OnEquipUdate(Entity *ent,unsigned char slot,bool Inbound );
	void OnClassUpdate(Entity *ent,bool Inbound );
	void OnCellChange(Entity *ent,bool Inbound );
	void OnRaceUpdate(Entity *ent,bool Inbound );
	void OnGenderUpdate(Entity *ent,bool Inbound );
	void OnAnimationUpdate(Entity *ent,unsigned char AnimationID,bool Inbound );
	void Chat(Entity *ent,std::string Message,bool Inbound );
};