
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
*/
#pragma once
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <boost/signal.hpp>
#include "Entity.h"
#include "EntityManager.h"
#include "EntityUpdateManager.h"
#include <vector>
#include <queue>
#define AV_HEALTH 8
#define AV_MAGICKA 9
#define AV_FATIGUE 10
#include "Packets.h"
#define MASK_ALL 0xffffffff
class Entity;
class EntityPermission
{
	UINT32 Mask,Match; // value AND MASK == Match
public:
	unsigned int GetMask() {return Mask;}
	unsigned int GetMatch(){return Match;}
	void SetMask(UINT32 val){Mask=val;}
	void SetMatch(UINT32 val){Match=val;}
	bool operator==(UINT32 EntityID){return (EntityID & Mask) == Match; }
	bool operator==(Entity *ent);
	EntityPermission(UINT32 mask,UINT32 match): Mask(mask),Match(match){}
	~EntityPermission(){}
	EntityPermission(const EntityPermission &other){Mask = other.Mask; Match=other.Match;}
};
class Entity
{
	friend class EntityManager;
protected:
	Entity(EntityManager *mgr,UINT32 refID, bool TriggerEvents = false,bool GlobalSynch= false,
		float posX = 0 , float posY = 0 , float posZ = 0,UINT32 CellID = 0,UINT32 WorldID =0,
		float rotX = 0 , float rotY = 0 , float rotZ = 0,short health = 0,short magicka = 0 , short fatigue = 0 ,
		bool female = false,UINT32 race = 0,std::string name = std::string("Unnamed"),std::string classname = std::string("")):
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
		m_World = WorldID;
		memset(m_ActorValues,0,72*sizeof(short));
		memset(m_AnimationStatus,0,43*sizeof(BYTE));
		m_mgr->RegisterEntity(this);
		lock.unlock();
	}
	~Entity()
	{
		m_mgr->DeRegisterEntity(this);
	}
	boost::mutex lock;

private:
	EntityManager *m_mgr;
	short m_ActorValues[72];
	bool m_AnimationStatus[43];
	UINT32 m_Equip[MAX_EQUIPSLOTS]; // Enough
	float m_PosX,m_PosY,m_PosZ,m_RotX,m_RotY,m_RotZ;
	UINT32 m_RefID,m_CellID,m_WorldID,m_Race; 
	bool m_Actor,m_GlobalSynch,m_Female;//Player : is a player , Actor: is an actor , GlobalSynch: Is important for quests and must therefore always be synched
	bool m_TriggerEvents;
	std::string m_Name; // A std::string should not waste TOO much space 
	//std::string m_Class;
	void _Move(float PosX,float PosY,float PosZ);
	void _SetRotation(float RotX,float RotY,float RotZ);
	void _SetFemale(bool value);
	void _SetCell(UINT32 value,UINT32 WorldID);
	void _SetGlobalSynch(bool value);
	void _SetRace(UINT32 value);
	void _SetEquip(BYTE slot,UINT32 value);
	void _SetName(std::string Name);
	void _SetClassName(std::string Class);
	void _SetActorValue(BYTE ActorValue,short Value);
	void _SetAnimation(BYTE AnimationNo,bool Status);
public:
	
	void Move(float X,float Y,float Z,bool Inbound = false);
	void Rotate(float rX,float rY,float rZ,bool Inbound = false);
	void MoveNRot(float X,float Y,float Z,float rX,float rY,float rZ,bool Inbound = false);
	void SetFemale(bool value,bool Inbound = false);
	void SetCell(UINT32 value,UINT32 WorldID,bool Inbound = false);
	void SetGlobalSynch(bool value,bool Inbound = false);
	void SetRace(UINT32 value,bool Inbound = false);
	void SetEquip(BYTE slot,UINT32 value,bool Inbound = false);
	void SetName(std::string Name,bool Inbound = false);
	void SetClassName(std::string Class,bool Inbound = false);
	void SetActorValue(BYTE ActorValue,short Value,bool Inbound = false);
	void SetAnimation(BYTE AnimationNo,bool Status,bool Inbound = false);
	inline std::string Name()
	{
		return m_Name;
	}
	inline std::string ClassName()
	{
		return "";
		//return m_Class;
	}
	inline bool Female()
	{
		return m_Female;
	}
	inline BYTE Gender()
	{
		if(m_Female)
			return 1;
		return 0;
	}
	inline UINT32 RefID()
	{
		return m_RefID;
	}
	inline bool IsInInterior()
	{
		return m_IsInInterior;
	}
	inline UINT32 Equip(UINT32 slot)
	{
		if(slot < MAX_EQUIPSLOTS)
			return m_Equip[slot];
		else
			return 0;
	}
	inline UINT32 CellID()
	{
		return m_CellID;
	}
	inline float PosX()
	{
		return m_PosX;
	}
	inline float PosY()
	{
		return m_PosY;
	}
	inline float PosZ()
	{
		return m_PosZ;
	}
	inline float RotX()
	{
		return m_RotX;
	}
	inline float RotY()
	{
		return m_RotY;
	}
	inline float RotZ()
	{
		return m_RotZ;
	};
	inline signed short ActorValue(BYTE statid)
	{
		return m_ActorValues[statid];
	}
	inline bool GlobalSynch()
	{
		return m_GlobalSynch;
	}
	inline UINT32 Race()
	{
		return m_Race;
	}
	inline bool AnimationStatus(BYTE Status){
		return m_AnimationStatus[Status];
	}
	boost::signal<void(Entity *)>		EventLifeChange; //   value of Life
	boost::signal<void(Entity *)>		EventDeath; 
	boost::signal<void(Entity *)>		EventMagicka; // same as above
	boost::signal<void(Entity *)>		EventMagickaEmpty; // same as above 
	boost::signal<void(Entity *)>		EventFatigue; // same as above
	boost::signal<void(Entity *)>		EventFatigueEmpty; // same as above
	boost::signal<void(Entity *,std::string *)>	EventChat; // On Chat
};
using namespace ChunkType;
struct ChunkPermissions
{
	EntityPermission AV;
	EntityPermission Position;
	EntityPermission other;
	bool Match(UINT32 id,PkgChunk t) const 
	{
		switch (t)
		{
		case ActorValue:
			return AV == id;
		case Position:
		case Animation:
			return Position == id;
		default:
			return other == id;
		}
	}
	bool Match(Entity *ID,PkgChunk t)const
	{
		return Match(ID->RefID(),t);
	}
	ChunkPermissions(): AV(0,1),Position(0,1),other(0,1) // Keine schreibrechte 
	{
	}
};