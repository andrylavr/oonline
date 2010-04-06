
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
#include <boost/signals2.hpp>
#include "EntityManager.h"
#include "EntityUpdateManager.h"
#include <vector>
#include <queue>
#define AV_HEALTH 8
#define AV_MAGICKA 9
#define AV_FATIGUE 10
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
	bool operator==(UINT32 EntityID) const {return (EntityID & Mask) == Match; }
	bool operator==(Entity *ent) const;
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
		bool female = false,UINT32 race = 0,std::string name = std::string("Unnamed"),std::string classname = std::string(""));
	~Entity();
	boost::mutex lock;

private:
	EntityManager *m_mgr;
	short m_ActorValues[72];
	short m_ActorValueMod[72];
	BYTE m_Animation;
	UINT32 m_Equip[MAX_EQUIPSLOTS]; // Enough
	float m_PosX,m_PosY,m_PosZ,m_RotX,m_RotY,m_RotZ;
	UINT32 m_RefID,m_CellID,m_WorldID,m_Race; 
	bool m_Actor,m_GlobalSynch,m_Female;//Player : is a player , Actor: is an actor , GlobalSynch: Is important for quests and must therefore always be synced
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
	void _SetActorValueMod(BYTE ActorValue,short Mod);
	void _SetAnimation(BYTE Animation);
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
	void SetActorValueMod(BYTE ActorValue,short Mod,bool Inbound = false);
	void SetAnimation(BYTE AnimationNo,bool Inbound = false);
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
	inline UINT32 WorldID()
	{
		return m_WorldID;
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
	inline signed short BaseActorValue(BYTE statid)
	{
		return m_ActorValues[statid];
	}
	inline short ActorValueMod(BYTE slot)
	{
		return m_ActorValueMod[slot];
	}
	inline short EffectiveActorValue(BYTE statid)
	{
		return m_ActorValues[statid] + m_ActorValueMod[statid];
	}
	inline bool GlobalSynch()
	{
		return m_GlobalSynch;
	}
	inline UINT32 Race()
	{
		return m_Race;
	}
	inline BYTE AnimationStatus()
	{
		return m_Animation;
	}
	boost::signals2::signal<void(Entity *)>		EventLifeChange; //   value of Life
	boost::signals2::signal<void(Entity *)>		EventDeath; 
	boost::signals2::signal<void(Entity *)>		EventMagicka; // same as above
	boost::signals2::signal<void(Entity *)>		EventMagickaEmpty; // same as above 
	boost::signals2::signal<void(Entity *)>		EventFatigue; // same as above
	boost::signals2::signal<void(Entity *)>		EventFatigueEmpty; // same as above
	boost::signals2::signal<void(Entity *,std::string *)>	EventChat; // On Chat
};