/*
Copyright 2009   Julian Bangert aka masterfreek64 
This file is part of OblivionOnline.

OblivionOnline is free software; you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

OblivionOnline is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "main.h"
#include "GlobalDefines.h"
#include "GameClient.h"
#include "GameInject.h"
#include "GameAPI.h"
#include "ClientEntity.h"
#include "GameCommand.h"
#include "CommandWrapper.h"
//static queue<pair<Actor *,UINT32>> RemoveOneItemQueue; 
//static queue<pair<Actor *,UINT32>> EquipItemQueue; 

TESObjectREFR * GetRefrFromEntity( ClientEntity * ent )
{
	if(ent->Status() != STATUS_PLAYER)
		return (TESObjectREFR * )LookupFormByID(ent->RefID());
	else
		return (TESObjectREFR * )LookupFormByID(gClient->GetSpawnRefID(GetSpawnIDFromPlayerID(ent->RefID())));
}
bool InjectActorValue(ClientEntity *ent,BYTE slot, INT16 value)
{
	if(!ent)
		return false;
	TESObjectREFR * refr = GetRefrFromEntity(ent);
	if(!refr || !refr->IsActor())
		return false;
	else
	{
		Actor * actor = (Actor *)refr;
		int CurrentVal = actor->GetActorValue(slot);
		//TODO: Sync health, fatigue, magicka unmodifiedvalues as well. In general sync all modifiers here
		    
		switch(slot)
		{
		case AV_FATIGUE:
		case AV_HEALTH:
		case AV_MAGICKA:
			actor->ModActorBaseValue(slot,value - CurrentVal,0);
			//assert(actor->GetBaseActorValue(slot) == value);
			//TODO: Re-add this assertion here
			break;
		default:
			actor->ModActorValue(slot,value - CurrentVal,0);
			assert(actor->GetActorValue(slot) == value);
			break;
		}
	}
}
//Called every frame, BEFORE synch takes place, to fix up things
void InjectEquip_Handlebacklog()
{
	/*while(!RemoveOneItemQueue.empty())
	{
		RemoveOneItemCommand(RemoveOneItemQueue.front().first,RemoveOneItemQueue.front().second);
		RemoveOneItemQueue.pop();
	}
	while(!EquipItemQueue.empty())
	{
		EquipItemCommand(EquipItemQueue.front().first,EquipItemQueue.front().second);
		EquipItemQueue.pop();
	}*/
}
extern bool FindEquipped(TESObjectREFR* thisObj, UInt32 slotIdx, FoundEquipped* foundEquippedFunctor, double* result);
bool InjectEquip( ClientEntity *ent,BYTE slot,UINT32 formid )
{
	if(!ent)
		return false;
	TESObjectREFR * refr = GetRefrFromEntity(ent);
	if(!refr || !refr->IsActor())
		return false;
	else
	{
		Actor * act= (Actor*)refr;
		if(formid && LookupFormByID(formid))
		{		
			feGetObject getObject;
			double itemResult;
			UInt32* itemRef = (UInt32 *)&itemResult;
			if (FindEquipped(act, slot, &getObject, &itemResult)  ) // If we find nothing, there already is no equip
			{
				ent->AddUnequipItem(*itemRef);
				ent->AddRemoveItem(*itemRef);
				//UnEquipItemCommand(act,*itemRef);
				//RemoveOneItemQueue.push(pair<Actor *,UINT32>(act,*itemRef));
			}
			//AddOneItemCommand(act,formid);
			ent->AddAddItem(formid);
			//ent->AddEquipItem(formid);
		}
		else
		{
			//Unequip the item in that slot.
			feGetObject getObject;
			double itemResult;
			UInt32* itemRef = (UInt32 *)&itemResult;
			if (FindEquipped(act, slot, &getObject, &itemResult)  ) // If we find nothing, there already is no equip
			{
				ent->AddUnequipItem(*itemRef);
				//ent->AddRemoveItem(*itemRef);
				//UnEquipItemCommand(act,*itemRef);
				//RemoveOneItemQueue.push(pair<Actor *,UINT32>(act,*itemRef));
			}
		}
		SafeAddUpdateQueue(ent);
		
	}
	return true;
}

bool InjectAnimation( ClientEntity *ent,BYTE slot,bool Playing )
{
	TESObjectREFR * refr = GetRefrFromEntity(ent);
	if(!refr || !refr->IsActor())
		return false;
	else
	{
		//TODO: See CallCommandGeneric
		double result;
		// We wish to call PlayGroup. This has the parameters ( which are passed as flat array in arg1 ) 
		// AnimGroup ( a UINT16) , and 1 Integer ( flag, which we want to be "1" ) 
		UInt8 ParamData[sizeof(UINT16) + sizeof(UINT32)];
		Actor * actor = (Actor *)refr;
		// create a Script object
		UInt8	scriptObjBuf[sizeof(Script)];
		Script	* tempScriptObj = (Script *)scriptObjBuf;
		ScriptEventList evlist;
		evlist.m_eventList = NULL;
		evlist.m_script = tempScriptObj;
		evlist.m_unk1 = 0;
		evlist.m_vars = NULL;
		void	* scriptState = GetGlobalScriptStateObj();

		tempScriptObj->Constructor();
		tempScriptObj->MarkAsTemporary();
		if(Playing)
			*((UINT16 *)ParamData) = slot; // Set parameter 1 ( aniom group) 
		else 
			*((UINT16 *)ParamData) = 0; // Play idle anim
		*((UINT32 *)(ParamData + 2)) = 1; // Flag to start immediately
		// Parameter list, parameters, thisOBj, arg3= param count, ScriptEventList ( what to put in there?) , Result ptr, and offset ( is 0 ok ? ) 
		Cmd_PlayGroup_Execute(kParams_CmdPlayGroup,ParamData,actor, 2,tempScriptObj,&evlist,&result,0); // NULL denotes incomplete params
		tempScriptObj->StaticDestructor();
	}
	return true;
}