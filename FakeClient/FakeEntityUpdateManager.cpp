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
#include "Packets.h"
#include "IOSystem.h"
#include "Entity.h"
#include "FakeClient.h"
using namespace raw;
extern NetworkConnection *conn;
void FakeEntityUpdateManager::OnAnimationUpdate(Entity *ent,bool Inbound)
{
	if(!Inbound)
	{
		Animation::Send(*conn,ent);
	}
	{
		if(!g_plot)
			return;
		m_mgr->GetIO() << GameMessage << "Object";
		m_mgr->GetIO() << ent->RefID() << "("<<ent->Name() << ") Animation " <<ent->AnimationStatus()<<endl;
	}
}
void FakeEntityUpdateManager::OnAVModUpdate(Entity *ent,unsigned char AVCode,bool Inbound)
{
	if(!Inbound)
	{
		ActorValueMod::Send(*conn,ent,AVCode);
	}
	{
		if(!g_plot)
			return;
		m_mgr->GetIO() << GameMessage << "Object: "<< ent->Name() << " Animation " <<ent->ActorValueMod(AVCode)<<endl;
	}
}
void FakeEntityUpdateManager::OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound)
{
	if(!Inbound)
	{
		ActorValue::Send(*conn,ent,AVCode);
	}
	{
		if(!g_plot)
			return;
		m_mgr->GetIO() << GameMessage << "Object" << 
			ent->RefID() << "("<< ent->Name() << ") BaseActorValue" << (unsigned int)AVCode << ": " << ent->BaseActorValue(AVCode) <<endl;
	}
}
void FakeEntityUpdateManager::OnCellChange(Entity *ent,UINT32 OldCell,bool Inbound)
{
	if(!Inbound)
	{
		CellID::Send(*conn,ent);
	}
	{
		EntityUpdateManager::OnCellChange(ent,OldCell,Inbound);
		if(!g_plot)
			return;
		m_mgr->GetIO() << GameMessage << "Object"<< 
			ent->RefID() << "("<<ent->Name() << ")Cell: " << ent->CellID() << "Worldspace:" << ent->WorldID() <<endl;
	}
}
void FakeEntityUpdateManager::OnClassUpdate(Entity *ent,bool Inbound)
{
	if(!Inbound)
	{
		Class::Send(*conn,ent);
	}
	{
		if(!g_plot)
			return;
		m_mgr->GetIO() << GameMessage << "Object" << 
			ent->RefID() << "("<<ent->Name() << ")Class: " << ent->ClassName() <<endl;
	}
}
void FakeEntityUpdateManager::OnEquipUdate(Entity *ent,unsigned char slot,bool Inbound)
{
	if(!Inbound)
	{
		Equip::Send(*conn,ent,slot);
	}
	{
		if(!g_plot)
			return;
		m_mgr->GetIO() << GameMessage << "Object" << 
			ent->RefID() << "("<<ent->Name() << ") Equip" <<(unsigned int)slot << ": " << ent->Equip(slot) <<endl;
	}
}
void FakeEntityUpdateManager::OnNameUpdate(Entity *ent,bool Inbound)
{
	if(!Inbound)
	{
		Name::Send(*conn,ent);
	}
	{
		if(!g_plot)
			return;

		m_mgr->GetIO() << GameMessage << "Object" << 
		ent->RefID() << "("<<ent->Name() << ")Name: " << ent->Name() <<endl;
	}
}
void FakeEntityUpdateManager::OnPositionUpdate(Entity *ent,bool Inbound)
{
	if(!Inbound)
	{
		Position::Send(*conn,ent);
	}
	{		
		if(!g_plot)
			return;
		m_mgr->GetIO() << GameMessage << "Object " << 
			ent->RefID() << "("<<ent->Name() << ")Position: " << ent->PosX() << "Y:"<<ent->PosY() << "Z:" << ent->PosZ()
			<< "rX" << ent->RotX() << "rY:" << ent->RotY() << "rZ" << ent->RotZ()<<endl;
	}
}
void FakeEntityUpdateManager::OnRaceUpdate(Entity *ent,bool Inbound)
{
	if(!Inbound)
	{
		Race::Send(*conn,ent);
	}
	{
		if(!g_plot)
			return;
		m_mgr->GetIO() << GameMessage << "Object " << 
			ent->RefID() << "("<<ent->Name() << ")Race: " << ent->Race()  << "Gender" << ent->Gender()<<endl;
	}
}
void FakeEntityUpdateManager::GlobalSend(Entity *ent, bool Inbound)
{

}
void FakeEntityUpdateManager::Chat(Entity *ent, std::string Message, bool Inbound)
{
}
void FakeEntityUpdateManager::OnCustomUpdate( Entity *ent,UINT32 Index,bool Inbound )
{
	if(!Inbound)
		Custom::Send(*conn,ent,Index);
	else
		IOStream::Instance() << GameMessage << "Custom attribute " << Index << "Value: " << ent->GetCustom(Index)<<endl;
}