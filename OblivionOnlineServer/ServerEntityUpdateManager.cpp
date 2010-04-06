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
#include "GlobalDefines.h"
#include "GameServer.h"
#include "ServerEntityUpdateManager.h"
#include "Entity.h"
#include "NetworkSystem.h"
#include "Packets.h"
#include <map>
#include "boost/foreach.hpp"
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/if.hpp"
#include "boost/lambda/bind.hpp"

using namespace std;
using namespace boost::lambda;
using namespace raw;
void ServerEntityUpdateManager::OnRaceUpdate( Entity *ent ,bool Inbound )
{
	BOOST_FOREACH(Player *p,_players)
	{
		if(!Inbound || (p!=ent) ) // If this is sent from an entity concerning itself 
		{
			Race::Send(*p,ent);
		}
	}
}

void ServerEntityUpdateManager::OnClassUpdate( Entity *ent ,bool Inbound)
{
	BOOST_FOREACH(Player *p,_players)
	{
		if(!Inbound || (p!=ent) ) // If this is sent from an entity concerning itself 
		{
			Class::Send(*p,ent);
		}
	}
}

void ServerEntityUpdateManager::OnNameUpdate( Entity *ent ,bool Inbound)
{
	BOOST_FOREACH(Player *p,_players)
	{
		if(!Inbound || (p!=ent) ) // If this is sent from an entity concerning itself 
		{
			Name::Send(*p,ent);
		}
	}
}

void ServerEntityUpdateManager::GlobalSend( Entity *ent ,bool Inbound)
{
	OnNameUpdate(ent,Inbound);
	OnRaceUpdate(ent,Inbound);
	OnNameUpdate(ent,Inbound);
	OnPositionUpdate(ent,Inbound);
	OnClassUpdate(ent,Inbound);
	OnCellChange(ent,ent->CellID(),Inbound);
}
void ServerEntityUpdateManager::OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound)
{
	BOOST_FOREACH(Player *p,_players)
	{
		if(!Inbound || (p!=ent) ) // If this is sent from an entity concerning itself 
		{
			ActorValue::Send(*p,ent,AVCode);
		}
	}
}

OO_API  void ServerEntityUpdateManager::OnAVModUpdate( Entity *ent,unsigned char AVCode,bool Inbound )
{
	BOOST_FOREACH(Player *p,_players)
	{
		if(!Inbound || (p!=ent) )
			ActorValueMod::Send(*p,ent,AVCode);
	}
}
void ServerEntityUpdateManager::OnPositionUpdate( Entity *ent,bool Inbound) /*Triggers Events and network code */
{
	BOOST_FOREACH(Player *p,_players)
	{
		if(!Inbound || (p!=ent) ) // If this is sent from an entity concerning itself 
		{
			Position::Send(*p,ent);
		}
	}
}
bool SendWorldState( Player * Player,bool LimitCell /*= true*/,EntityManager *m_mgr)
{
	for(map<UINT32,Entity *>::const_iterator i =  m_mgr->BeginObjects(); i != m_mgr->EndObjects() ; i++)
	{
		if(Player->CellID() != i->second->CellID())
			continue;
		else
		{
			//TODO: Send data
		}
	}
	return true;
}
void ServerEntityUpdateManager::OnCellChange( Entity *ent,UINT32 OldID,bool Inbound)
{
	BOOST_FOREACH(Player *p,_players)
	{
		if(!Inbound || (p!=ent) ) // If this is sent from an entity concerning itself 
		{
			Position::Send(*p,ent);
		}
	}
}

void ServerEntityUpdateManager::OnEquipUdate( Entity *ent,BYTE slot,bool Inbound)
{
	BOOST_FOREACH(Player *p,_players)
	{
		if(!Inbound || (p!=ent) ) // If this is sent from an entity concerning itself 
		{
			Equip::Send(*p,ent,slot);
		}
	}
}

void ServerEntityUpdateManager::OnAnimationUpdate( Entity *ent ,bool Inbound )
{
	BOOST_FOREACH(Player *p,_players)
	{
		if(!Inbound || (p!=ent) ) // If this is sent from an entity concerning itself 
		{
			Animation::Send(*p,ent);
		}
	}
}
void ServerEntityUpdateManager::Chat(Entity *ent,std::string Message,bool Inbound )
{
	std::stringstream messagebuf;
	messagebuf << ent->Name() << ":"<< Message;
	IOStream::Instance() << PlayerChat << messagebuf<<endl;
	BOOST_FOREACH(Player *p,_players)
	{
		raw::Chat::Send(*p,ent,messagebuf.str());
	}
}
OO_API  bool ServerEntityUpdateManager::NewPlayerID( UINT32 ID )
{
	throw std::runtime_error("Illicit PlayerID chunk sent to server!");
}