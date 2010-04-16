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
#include "main.h"
#include "GameInject.h"
#include "ClientEntityUpdateManager.h"
#include "Packets.h"
void ClientEntityUpdateManager::OnAnimationUpdate(Entity *ent,bool Inbound)
{
	if(!Inbound)
		raw::Animation::Send(gClient->GetConnection(),ent);
	else
		InjectAnimation((ClientEntity *)ent,ent->AnimationStatus());
}
void ClientEntityUpdateManager::OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound)
{
	if(!Inbound)
		raw::ActorValue::Send(gClient->GetConnection(),ent,AVCode);
	else
		InjectActorValue((ClientEntity *)ent,AVCode,(UINT32)ent->BaseActorValue(AVCode));// This causes C++ to raw re-interpret the data
}
void ClientEntityUpdateManager::OnCellChange(Entity *ent,UINT32 OldCell,bool Inbound)
{
	if( (ent->RefID() == gClient->GetLocalPlayer())	 && !gClient->GetIsMasterClient() )
		gClient->EmptyPlayerCell();
	if(!Inbound)
		raw::CellID::Send(gClient->GetConnection(),ent);
	else
	{
		SafeAddUpdateQueue(ent);
	}
}
void ClientEntityUpdateManager::OnClassUpdate(Entity *ent,bool Inbound)
{

}
void ClientEntityUpdateManager::OnEquipUdate(Entity *ent,unsigned char slot,bool Inbound)
{
	if(!Inbound)
		raw::Equip::Send(gClient->GetConnection(),ent,slot);
	else
		InjectEquip((ClientEntity *)ent,slot,ent->Equip(slot));
}
void ClientEntityUpdateManager::OnNameUpdate(Entity *ent,bool Inbound)
{
}
void ClientEntityUpdateManager::OnPositionUpdate(Entity *ent,bool Inbound)
{
	if(!Inbound)
		raw::Position::Send(gClient->GetConnection(),ent);
	else
		SafeAddUpdateQueue(ent);
}
void ClientEntityUpdateManager::OnRaceUpdate(Entity *ent,bool Inbound)
{

}
void ClientEntityUpdateManager::OnAVModUpdate( Entity *ent,unsigned char AVCode,bool Inbound )
{
	if(!Inbound)
		raw::ActorValueMod::Send(gClient->GetConnection(),ent,AVCode);
	else
		SafeAddUpdateQueue(ent);
}
void ClientEntityUpdateManager::Chat(Entity *ent,std::string Message,bool Inbound )
{}
void ClientEntityUpdateManager::GlobalSend(Entity *ent, bool Inbound)
{}

bool ClientEntityUpdateManager::NewPlayerID( UINT32 ID )
{
	gClient->SetPlayerID(ID);
	return true;
}

void ClientEntityUpdateManager::NewClientStatus( bool IsMasterClient )
{
	gClient->SetIsMasterClient(IsMasterClient);
}