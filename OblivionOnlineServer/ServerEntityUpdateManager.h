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
#include "PlayerManager.h"
#include "EntityUpdateManager.h"

class  ServerEntityUpdateManager : public EntityUpdateManager
{
protected:
	PlayerManager &_players;
	NetworkSystem *m_net;
public:
	ServerEntityUpdateManager(PlayerManager *players,EntityManager * mgr,NetworkSystem * netsys) : EntityUpdateManager(mgr),_players(*players)
	{
		m_net = netsys;
	}
	NetworkSystem *GetNetsys()
	{
		return m_net;
	}
	OO_API virtual void OnPositionUpdate(Entity *ent,bool Inbound );//Triggers Events and network code;
	OO_API virtual void OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound );
	OO_API virtual void OnAVModUpdate(Entity *ent,unsigned char AVCode,bool Inbound);
	OO_API virtual  void GlobalSend(Entity *ent,bool Inbound );
	OO_API virtual void OnNameUpdate(Entity *ent,bool Inbound );
	OO_API virtual void OnEquipUdate(Entity *ent,unsigned char slot,bool Inbound );
	OO_API virtual void OnClassUpdate(Entity *ent,bool Inbound );
	OO_API virtual void OnCellChange(Entity *ent,UINT32 oldCell, bool Inbound );
	OO_API virtual void OnRaceUpdate(Entity *ent,bool Inbound );
	OO_API virtual void OnAnimationUpdate(Entity *ent,bool Inbound );
	OO_API virtual void Chat(Entity *ent,std::string Message,bool Inbound );
	OO_API virtual bool NewPlayerID(UINT32 ID);
};