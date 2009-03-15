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
#include "GameServer.h"
#include "EntityUpdateManager.h"
#include "Entity.h"
#include "NetworkSystem.h"
#include "Packets.h"
#include <map>
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/if.hpp"
#include "boost/lambda/bind.hpp"

using namespace std;
using namespace boost::lambda;
void EntityUpdateManager::OnRaceUpdate( Entity *ent ,bool Inbound )
{
	UINT32 race = ent->Race();
	for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
	{
		if(i->second != ent || !Inbound)
		{
			m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(Race),Race,(BYTE*)&race);
		}
	}
}

void EntityUpdateManager::OnGenderUpdate( Entity *ent ,bool Inbound)
{
	BYTE Data = ent->Gender();
	for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
	{
		if(i->second != ent || !Inbound)
	{

			m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(Gender),Gender,&Data);
		}
	}
}

void EntityUpdateManager::OnClassUpdate( Entity *ent ,bool Inbound)
{
	for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
	{
		if(i->second != ent || !Inbound)
		{
			//Send out data
		}
	}
}

void EntityUpdateManager::OnNameUpdate( Entity *ent ,bool Inbound)
{
	for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
	{
		if(i->second != ent || !Inbound)
		{
			//Send out data
		}
	}
}

void EntityUpdateManager::GlobalSend( Entity *ent ,bool Inbound)
{
	float ChunkData[6] =
	{
		ent->PosX(),
		ent->PosY(),
		ent->PosZ(),
		ent->RotX(),
		ent->RotY(),
		ent->RotZ()
	};

	for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
	{
		if(i->second != ent || !Inbound)
		{
			m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(Position),Position,(BYTE *)&ChunkData);
			m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(CellID),CellID,(BYTE*)&ChunkData);
			//TODO: send out stats
		}
	}
}
void EntityUpdateManager::OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound)
{
	short Value = ent->ActorValue(AVCode);
	if(ent->Status() < STATUS_PLAYER)
	{
		for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
		{
			if(i->first != m_net->GetMasterClient()  || !Inbound)
			{
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(ActorValue),ActorValue,(BYTE *)&Value);
			}
		}
	}
	else
	{
		for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
		{
			if(i->first != ent->RefID() || !Inbound)
			{
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(ActorValue),ActorValue,(BYTE *)&Value);
			}
		}
	}
}
void EntityUpdateManager::OnPositionUpdate( Entity *ent,bool Inbound) /*Triggers Events and network code */
{
	float ChunkData[6] =
	{
		ent->PosX(),
		ent->PosY(),
		ent->PosZ(),
		ent->RotX(),
		ent->RotY(),
		ent->RotZ()
	};
	UINT32 CellData = ent->CellID();
	if(ent->Status() < STATUS_PLAYER)
	{
		for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
		{			
			if((m_net->GetMasterClient() != i->first && i->second->CellID() == ent->CellID()) || !Inbound)
			{
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(CellID),CellID,(BYTE*)&CellData);
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(Position),Position,(BYTE*)&ChunkData);
			}
		}
	}
	else
	{
		for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
		{			
			if((ent->RefID() != i->first && i->second->CellID() == ent->CellID()) || !Inbound)
			{
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(CellID),CellID,(BYTE*)&CellData);
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(Position),Position,(BYTE*)&ChunkData);
			}
		}
	}
}
bool SendWorldState( Entity * Player,bool LimitCell /*= true*/,EntityManager *m_mgr)
{
	for(map<UINT32,Entity *>::const_iterator i =  m_mgr->BeginObjects(); i != m_mgr->EndObjects() ; i++)
	{
		if(Player->CellID() != i->second->CellID())
			continue;
		else
		{
			//TODO: Send out player data
		}
	}
	return true;
}
void EntityUpdateManager::OnCellChange( Entity *ent,bool Inbound)
{
	BYTE ChunkData[5];
	*((UINT32 *)ChunkData) = ent->CellID();
	ChunkData[4] = ent->IsInInterior() ? 1 : 0;
	if(ent->Status() < STATUS_PLAYER)
	{
		for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
		{
			if( i->first != m_net->GetMasterClient()  || !Inbound) // !Inbound means that MC will be overriden
			{
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(CellID),CellID,(BYTE*)&ChunkData);
			}
		}
	}
	else
	{
		for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
		{
			if( i->first != ent->RefID()  || !Inbound)
			{
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(CellID),CellID,(BYTE*)&ChunkData);
			}
			else
			{
				SendWorldState(i->second,false,m_mgr);
			}
		}
	}
}

void EntityUpdateManager::OnEquipUdate( Entity *ent,BYTE slot,bool Inbound)
{
	BYTE ChunkData[5];
	ChunkData[0] = slot;
	*(UINT32 *)(ChunkData +1) = ent->Equip(slot);

	if(ent->Status() < STATUS_PLAYER)
	{
		for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
		{
			if( i->first != m_net->GetMasterClient() || !Inbound)
			{
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(Equip),Equip,(BYTE*)&ChunkData);
			}
		}
	}
	else
	{
		for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
		{
			if(i->first != ent->RefID() || !Inbound)
			{
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(Equip),Equip,(BYTE*)&ChunkData);
			}
		}
	}
}

void EntityUpdateManager::OnAnimationUpdate( Entity *ent,unsigned char AnimationID ,bool Inbound )
{
	BYTE ChunkData[2] = {AnimationID,ent->AnimationStatus(AnimationID)};
	if(ent->Status() < STATUS_PLAYER)
	{
		for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
		{
			if( i->first != m_net->GetMasterClient() || !Inbound)
			{
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(Equip),Equip,(BYTE*)&ChunkData);
			}
		}
	}
	else
	{
		for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
		{
			if(i->first != ent->RefID() || !Inbound)
			{
				m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),GetMinChunkSize(Equip),Equip,(BYTE*)&ChunkData);
			}
		}
	}
}
void EntityUpdateManager::Chat(Entity *ent,std::string Message,bool Inbound )
{
	BYTE *buf = (BYTE *)malloc(Message.length() + 2);
	*(UINT16 *) buf = Message.length();
	memcpy(buf + 2,Message.c_str(),Message.length());
	for(map<UINT32,Entity *>::const_iterator i =  m_mgr->GetPlayerList().begin(); i != m_mgr->GetPlayerList().end() ; i++)
	{
		m_net->SendChunk(i->second->RefID(),ent->RefID(),ent->Status(),Message.length() + 2,ChunkType::Chat,buf);
	}
	free(buf);
}