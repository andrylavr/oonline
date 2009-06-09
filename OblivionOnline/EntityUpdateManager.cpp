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
#include "../OOCommon/NetSend.h"
#include "GameInject.h"

void EntityUpdateManager::OnAnimationUpdate(Entity *ent,unsigned char AnimationID,bool Inbound)
{
	if(!Inbound)
		NetSendAnimation(gClient->GetServerStream(),ent->RefID(),ent->Status(),AnimationID,ent->AnimationStatus(AnimationID));
	else
		InjectAnimation((ClientEntity *)ent,AnimationID,ent->AnimationStatus(AnimationID));
}
void EntityUpdateManager::OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound)
{
	if(!Inbound)
		NetSendActorValue(gClient->GetServerStream(),ent->RefID(),ent->Status(),AVCode,ent->ActorValue(AVCode));
	else
		InjectActorValue((ClientEntity *)ent,AVCode,(UINT32)ent->ActorValue(AVCode));// This causes C++ to raw re-interpret the data
}
void EntityUpdateManager::OnCellChange(Entity *ent,bool Inbound)
{
	if(!Inbound)
		NetSendCellID(gClient->GetServerStream(),ent->RefID(),ent->Status(),ent->CellID(),ent->IsInInterior());
	else
	{
		SafeAddUpdateQueue(ent);
	}
}
void EntityUpdateManager::OnClassUpdate(Entity *ent,bool Inbound)
{

}
void EntityUpdateManager::OnEquipUdate(Entity *ent,unsigned char slot,bool Inbound)
{
	if(!Inbound)
		NetSendEquip(gClient->GetServerStream(),ent->RefID(),ent->Status(),slot,ent->Equip(slot));
	else
		InjectEquip((ClientEntity *)ent,slot,ent->Equip(slot));
}
void EntityUpdateManager::OnGenderUpdate(Entity *ent,bool Inbound)
{
}
void EntityUpdateManager::OnNameUpdate(Entity *ent,bool Inbound)
{
}
void EntityUpdateManager::OnPositionUpdate(Entity *ent,bool Inbound)
{
	if(!Inbound)
		NetSendPosition(gClient->GetServerStream(),ent->RefID(),ent->Status(),ent->PosX(),ent->PosY()
		,ent->PosZ(),ent->RotX(),ent->RotY(),ent->RotZ());
	else
		SafeAddUpdateQueue(ent);
}
void EntityUpdateManager::OnRaceUpdate(Entity *ent,bool Inbound)
{

}