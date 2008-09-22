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
#ifndef ENTITYUPDATEMANAGER_H
#define ENTITYUPDATEMANAGER_H
#include "main.h"
#include "../OOCommon/NetSend.h"
inline void SafeAddUpdateQueue(Entity * ent)
{	
	if(!UpdateQueue.empty())
	{
		deque<Entity *>::iterator UpdateIterator;
		UpdateIterator = UpdateQueue.begin();
		while(1)
		{
			if(UpdateIterator == UpdateQueue.end())
				break; //really bad , but fixes some crashes ??
			if((*UpdateIterator) == ent )
				return;
			UpdateIterator++;
		}
	}
	UpdateQueue.push_back(ent);
}
void EntityUpdateManager::OnAnimationUpdate(Entity *ent,unsigned char AnimationID,bool Inbound)
{
	if(!Inbound)
		NetSendAnimation(outnet.GetPacket(),ent->RefID(),ent->Status(),AnimationID,ent->AnimationStatus(AnimationID));
	else
		SafeAddUpdateQueue(ent);
}
void EntityUpdateManager::OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound)
{
	if(!Inbound)
		NetSendActorValue(outnet.GetPacket(),ent->RefID(),ent->Status(),AVCode,ent->ActorValue(AVCode));
	else
		SafeAddUpdateQueue(ent);
}
void EntityUpdateManager::OnCellChange(Entity *ent,bool Inbound)
{
	if(!Inbound)
		NetSendCellID(outnet.GetPacket(),ent->RefID(),ent->Status(),ent->CellID(),ent->IsInInterior());
	else
		SafeAddUpdateQueue(ent);
}
void EntityUpdateManager::OnClassUpdate(Entity *ent,bool Inbound)
{

}
void EntityUpdateManager::OnEquipUdate(Entity *ent,unsigned char slot,bool Inbound)
{
	if(!Inbound)
		NetSendEquip(outnet.GetPacket(),ent->RefID(),ent->Status(),slot,ent->Equip(slot));
	else
		SafeAddUpdateQueue(ent);
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
		NetSendPosition(outnet.GetPacket(),ent->RefID(),ent->Status(),ent->PosX(),ent->PosY()
		,ent->PosZ(),ent->RotX(),ent->RotY(),ent->RotZ());
	else
		SafeAddUpdateQueue(ent);
}
void EntityUpdateManager::OnRaceUpdate(Entity *ent,bool Inbound)
{

}
#endif