/*

Copyright(c) 2007-2010   Julian Bangert 

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
#include "Entity.h"
#include "FakeClient.h"
void FakeEntityUpdateManager::OnAnimationUpdate(Entity *ent,unsigned char AnimationID,bool Inbound)
{
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << "Object";
	m_mgr->GetIO() << 
		ent->RefID() << "("<<ent->Name() << ") Animation " << (unsigned int)AnimationID <<
		(ent->AnimationStatus(AnimationID) ? "Started" : "Stopped") << endl;
}
void FakeEntityUpdateManager::OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound)
{
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << "Object" << 
		ent->RefID() << "("<< ent->Name() << ") ActorValue" << (unsigned int)AVCode << ": " << ent->ActorValue(AVCode) <<endl;
}
void FakeEntityUpdateManager::OnCellChange(Entity *ent,UINT32 OldCell,bool Inbound)
{
	EntityUpdateManager::OnCellChange(ent,OldCell,Inbound);
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << "Object"<< 
		ent->RefID() << "("<<ent->Name() << ")Cell: " << ent->CellID() <<endl;
}
void FakeEntityUpdateManager::OnClassUpdate(Entity *ent,bool Inbound)
{
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << "Object" << 
		ent->RefID() << "("<<ent->Name() << ")Class: " << ent->ClassName() <<endl;
}
void FakeEntityUpdateManager::OnEquipUdate(Entity *ent,unsigned char slot,bool Inbound)
{
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << "Object" << 
		ent->RefID() << "("<<ent->Name() << ") Equip" <<(unsigned int)slot << ": " << ent->Equip(slot) <<endl;
}
void FakeEntityUpdateManager::OnGenderUpdate(Entity *ent,bool Inbound)
{
	if(!g_plot)
		return;

	m_mgr->GetIO() << GameMessage << "Object" << 
		ent->RefID() << "("<<ent->Name() << ")female: " << ent->Female() <<endl;
}
void FakeEntityUpdateManager::OnNameUpdate(Entity *ent,bool Inbound)
{
	if(!g_plot)
		return;

	m_mgr->GetIO() << GameMessage << "Object" << 
		ent->RefID() << "("<<ent->Name() << ")Name: " << ent->Name() <<endl;
}
void FakeEntityUpdateManager::OnPositionUpdate(Entity *ent,bool Inbound)
{
	if(!g_plot)
		return;

	m_mgr->GetIO() << GameMessage << ((ent->Status()==STATUS_PLAYER)?"Player ":"Object ") << 
		ent->RefID() << "("<<ent->Name() << ")Position: " << ent->PosX() << "Y:"<<ent->PosY() << "Z:" << ent->PosZ()
		<< "rX" << ent->RotX() << "rY:" << ent->RotY() << "rZ" << ent->RotZ()<<endl;
}
void FakeEntityUpdateManager::OnRaceUpdate(Entity *ent,bool Inbound)
{
	if(!g_plot)
		return;
	m_mgr->GetIO() << GameMessage << ((ent->Status()==STATUS_PLAYER)?"Player ":"Object ") << 
		ent->RefID() << "("<<ent->Name() << ")race: " << ent->Race() <<endl;
}
void FakeEntityUpdateManager::GlobalSend(Entity *ent, bool Inbound)
{

}
void FakeEntityUpdateManager::Chat(Entity *ent, std::string Message, bool Inbound)
{
}