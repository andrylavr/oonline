/*

Copyright(c) 2007-2008   Julian Bangert aka masterfreek64

This file is part of OblivionOnline.

OblivionOnline is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

OblivionOnline is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

*/
#include "GlobalDefines.h"
#include "IOSystem.h"
#include "EntityUpdateManager.h"
#include "Entity.h"
#include "FakeClient.h"
void EntityUpdateManager::OnAnimationUpdate(Entity *ent,unsigned char AnimationID,bool Inbound)
{
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << (((ent->Status()==STATUS_PLAYER)?"Player ":"Object "));
	m_mgr->GetIO() << 
		ent->RefID() << "("<<ent->Name() << ") Animation " << (unsigned int)AnimationID <<
		(ent->AnimationStatus(AnimationID) ? "Started" : "Stopped") << endl;
}
void EntityUpdateManager::OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound)
{
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << (((ent->Status()==STATUS_PLAYER)?"Player ":"Object ")) << 
		ent->RefID() << "("<< ent->Name() << ") ActorValue" << (unsigned int)AVCode << ": " << ent->ActorValue(AVCode) <<endl;
}
void EntityUpdateManager::OnCellChange(Entity *ent,bool Inbound)
{
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << (((ent->Status()==STATUS_PLAYER)?"Player ":"Object "))<< 
		ent->RefID() << "("<<ent->Name() << ")Cell: " << ent->CellID() <<endl;
}
void EntityUpdateManager::OnClassUpdate(Entity *ent,bool Inbound)
{
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << (((ent->Status()==STATUS_PLAYER)?"Player ":"Object ")) << 
		ent->RefID() << "("<<ent->Name() << ")Class: " << ent->ClassName() <<endl;
}
void EntityUpdateManager::OnEquipUdate(Entity *ent,unsigned char slot,bool Inbound)
{
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << (((ent->Status()==STATUS_PLAYER)?"Player ":"Object ")) << 
		ent->RefID() << "("<<ent->Name() << ") Equip" <<(unsigned int)slot << ": " << ent->Equip(slot) <<endl;
}
void EntityUpdateManager::OnGenderUpdate(Entity *ent,bool Inbound)
{
	if(!g_plot)
		return;

	m_mgr->GetIO() << GameMessage << (((ent->Status()==STATUS_PLAYER)?"Player ":"Object ")) << 
		ent->RefID() << "("<<ent->Name() << ")female: " << ent->Female() <<endl;
}
void EntityUpdateManager::OnNameUpdate(Entity *ent,bool Inbound)
{
	if(!g_plot)
		return;

	m_mgr->GetIO() << GameMessage << (((ent->Status()==STATUS_PLAYER)?"Player ":"Object ")) << 
		ent->RefID() << "("<<ent->Name() << ")Name: " << ent->Name() <<endl;
}
void EntityUpdateManager::OnPositionUpdate(Entity *ent,bool Inbound)
{
	if(!g_plot)
		return;

	m_mgr->GetIO() << GameMessage << ((ent->Status()==STATUS_PLAYER)?"Player ":"Object ") << 
		ent->RefID() << "("<<ent->Name() << ")Position: " << ent->PosX() << "Y:"<<ent->PosY() << "Z:" << ent->PosZ()
		<< "rX" << ent->RotX() << "rY:" << ent->RotY() << "rZ" << ent->RotZ()<<endl;
}
void EntityUpdateManager::OnRaceUpdate(Entity *ent,bool Inbound)
{
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << ((ent->Status()==STATUS_PLAYER)?"Player ":"Object ") << 
		ent->RefID() << "("<<ent->Name() << ")race: " << ent->Race() <<endl;
}