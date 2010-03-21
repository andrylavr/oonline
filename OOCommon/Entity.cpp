/*

Copyright(c) 2009   Julian Bangert aka masterfreek64

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
#include "Entity.h"
void Entity::SetCell( UINT32 value,UINT32 World,bool Inbound /*= false*/ )
{
	lock.lock();
	if(CellID() != value || m_WorldID != World)
	{
		UINT32 oldvalue = m_CellID;
		_SetCell(value,World);
		m_mgr->GetUpdateMgr()->OnCellChange(this,oldvalue,Inbound);
	}
	lock.unlock();
}

void Entity::Move( float X,float Y,float Z,bool Inbound /*= false*/ )
{
	lock.lock();
	if(m_PosX != X || m_PosY != Y || m_PosZ != Z)
	{
		_Move(X,Y,Z);
		m_mgr->GetUpdateMgr()->OnPositionUpdate(this,Inbound);
	}
	lock.unlock();
}

void Entity::_Move( float PosX,float PosY,float PosZ )
{
	m_PosX = PosX;
	m_PosY = PosY;
	m_PosZ = PosZ;
}

void Entity::_SetRotation( float RotX,float RotY,float RotZ )
{
	m_RotX = RotX;
	m_RotY = RotY;
	m_RotZ = RotZ;
}

void Entity::_SetFemale( bool value )
{
	m_Female = value;
}

void Entity::_SetCell( UINT32 value,UINT32 WorldID )
{
	m_CellID = value;
	m_WorldID = WorldID;
}

void Entity::_SetRace( UINT32 value )
{
	m_Race = value;
}

void Entity::_SetEquip( BYTE slot,UINT32 value )
{
	if(slot < MAX_EQUIPSLOTS)
	{
		m_Equip[slot ] = value;
	}
}

void Entity::_SetGlobalSynch( bool value )
{
	m_GlobalSynch  = value; 
	//TODO: Synch object out
}

void Entity::_SetName( std::string Name )
{
	m_Name = Name;
}

void Entity::_SetActorValue( BYTE ActorValue,short Value )
{
	if(ActorValue < 72)
		m_ActorValues[ActorValue] = Value;
}

void Entity::_SetClassName( std::string Class )
{
	//m_Class = Class;
}

void Entity::Rotate( float rX,float rY,float rZ,bool Inbound /*= false*/ )
{
	lock.lock();
	if(m_RotX != rX || m_RotY != rY || m_RotZ != rZ)
	{
		_SetRotation(rX,rY,rZ);
		m_mgr->GetUpdateMgr()->OnPositionUpdate(this,Inbound);
	}
	lock.unlock();
}

void Entity::MoveNRot( float X,float Y,float Z,float rX,float rY,float rZ,bool Inbound /*= false*/ )
{
	lock.lock();
	if(m_PosX != X || m_PosY != Y || m_PosZ != Z || m_RotX != rX || m_RotY != rY || m_RotZ != rZ )
	{
		_Move(X,Y,Z);
		_SetRotation(rX,rY,rZ);
		m_mgr->GetUpdateMgr()->OnPositionUpdate(this,Inbound);
	}
	lock.unlock();
}

void Entity::SetFemale( bool value,bool Inbound /*= false*/ )
{
	lock.lock();
	_SetFemale(value);
	m_mgr->GetUpdateMgr()->OnGenderUpdate(this,Inbound);
	lock.unlock();
}

void Entity::SetGlobalSynch( bool value,bool Inbound /*= false*/ )
{
	_SetGlobalSynch(value);
	//TODO: Synch object out
}

void Entity::SetRace( UINT32 value,bool Inbound /*= false*/ )
{
	lock.lock();
	_SetRace(value);
	m_mgr->GetUpdateMgr()->OnRaceUpdate(this,Inbound);
	lock.unlock();
}

void Entity::SetEquip( BYTE slot,UINT32 value,bool Inbound /*= false*/ )
{
	lock.lock();
	if(Equip(slot) != value)
	{
		_SetEquip(slot,value);
		m_mgr->GetUpdateMgr()->OnEquipUdate(this,slot,Inbound);
	}
	lock.unlock();
}

void Entity::SetName( std::string Name,bool Inbound /*= false*/ )
{
	lock.lock();
	_SetName(Name);
	m_mgr->GetUpdateMgr()->OnNameUpdate(this,Inbound);
	lock.unlock();
}

void Entity::SetClassName( std::string Class,bool Inbound /*= false*/ )
{
	lock.lock();
	_SetClassName(Class);
	m_mgr->GetUpdateMgr()->OnClassUpdate(this,Inbound);
	lock.unlock();
}

void Entity::SetActorValue( BYTE ActorValue,short Value,bool Inbound /*= false*/ )
{
	lock.lock();
	if(this->ActorValue(ActorValue) != Value)
	{
		_SetActorValue(ActorValue,Value);
		m_mgr->GetUpdateMgr()->OnAVUpdate(this,ActorValue,Inbound);
		if(ActorValue == AV_HEALTH)
		{
			EventLifeChange(this);
			if(Value <= 0)
				EventDeath(this);
		}
		else if(ActorValue == AV_MAGICKA)
		{
			EventMagicka(this);
			if(Value <= 0)
				EventMagickaEmpty(this);
		}
		else if(ActorValue == AV_FATIGUE)
		{
			EventFatigue(this);
			if(Value <= 0)
				EventFatigueEmpty(this);
		}
	}
	lock.unlock();
}

void Entity::SetAnimation( BYTE AnimationNo,bool Status,bool Inbound /*= false*/ )
{
	lock.lock();
	if(AnimationStatus(AnimationNo) != Status)
	{
		_SetAnimation(AnimationNo,Status);
		m_mgr->GetUpdateMgr()->OnAnimationUpdate(this,AnimationNo,Inbound);
	}		
	lock.unlock();
}

void Entity::_SetAnimation( BYTE AnimationNo,bool Status )
{
	if(AnimationNo < 43)
		m_AnimationStatus[AnimationNo] = Status;
}

Entity::~Entity()
{
	m_mgr->DeRegisterEntity(this);
}

Entity::Entity( EntityManager *mgr,UINT32 refID, bool TriggerEvents /*= false*/,bool GlobalSynch/*= false*/, float posX /*= 0 */, float posY /*= 0 */, float posZ /*= 0*/,UINT32 CellID /*= 0*/,UINT32 WorldID /*=0*/, float rotX /*= 0 */, float rotY /*= 0 */, float rotZ /*= 0*/,short health /*= 0*/,short magicka /*= 0 */, short fatigue /*= 0 */, bool female /*= false*/,UINT32 race /*= 0*/,std::string name /*= std::string("Unnamed")*/,std::string classname /*= std::string("")*/ ) :
lock(),m_Name(name),EventChat(),EventFatigueEmpty(),EventFatigue(),EventMagicka(),EventMagickaEmpty(),EventDeath(),
EventLifeChange()		//,m_Class(classname)
{
	lock.lock();
	m_mgr = mgr;
	m_RefID = refID;
	m_PosX = posX;
	m_PosY = posY;
	m_PosZ = posZ;
	m_RotX = rotX;
	m_RotY = rotY;
	m_RotZ = rotZ;
	m_CellID = CellID;
	m_GlobalSynch = true;
	m_TriggerEvents = TriggerEvents;
	m_Female = female;
	m_Race = race;
	//m_Name = name;
	//m_Class = classname;
	m_WorldID = WorldID;
	memset(m_ActorValues,0,72*sizeof(short));
	memset(m_AnimationStatus,0,43*sizeof(BYTE));
	m_mgr->RegisterEntity(this);
	lock.unlock();
}

void Entity::_SetActorValueMod( BYTE ActorValue,short Mod )
{
	m_ActorValueMod[ActorValue] = Mod;
}
bool EntityPermission::operator==( Entity *ent ) const
{
	return (*this) == ent->RefID();
}