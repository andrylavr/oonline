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
#include "Entity.h"
#include "GameCommand.h"
#include "CommandWrapper.h"
static queue<pair<Actor *,UINT32>> RemoveOneItemQueue; 
static queue<pair<Actor *,UINT32>> EquipItemQueue; 

TESObjectREFR * GetRefrFromEntity( Entity * ent )
{
	if(ent->Status() != STATUS_PLAYER)
		return (TESObjectREFR * )LookupFormByID(ent->RefID());
	else
		return (TESObjectREFR * )LookupFormByID(gClient->GetSpawnRefID(GetSpawnIDFromPlayerID(ent->RefID())));
}
bool InjectActorValue(Entity *ent,BYTE slot, INT16 value)
{
	if(!ent)
		return false;
	TESObjectREFR * refr = GetRefrFromEntity(ent);
	if(!refr || !refr->IsActor())
		return false;
	else
	{
		Actor * actor = (Actor *)refr;
		actor->SetActorValue(slot,value);
		ASSERT(actor->GetActorValue(slot) == value);
	}
}
//Called every frame, BEFORE synch takes place, to fix up things
void InjectEquip_Handlebacklog()
{
	while(!RemoveOneItemQueue.empty())
	{
		RemoveOneItemCommand(RemoveOneItemQueue.front().first,RemoveOneItemQueue.front().second);
		RemoveOneItemQueue.pop();
	}
	while(!EquipItemQueue.empty())
	{
		EquipItemCommand(EquipItemQueue.front().first,EquipItemQueue.front().second);
		EquipItemQueue.pop();
	}
}
extern bool FindEquipped(TESObjectREFR* thisObj, UInt32 slotIdx, FoundEquipped* foundEquippedFunctor, double* result);
bool InjectEquip( Entity *ent,BYTE slot,UINT32 formid )
{
	if(!ent)
		return false;
	TESObjectREFR * refr = GetRefrFromEntity(ent);
	if(!refr || !refr->IsActor())
		return false;
	else
	{
		Actor * act= (Actor*)refr;
		if(!formid || !LookupFormByID(formid))
		{
			AddOneItemCommand(act,formid);
			EquipItemQueue.push(pair<Actor *,UINT32>(act,formid));
		}
		else
		{
			//Unequip the item in that slot.
			feGetObject getObject;
			double itemResult;
			UInt32* itemRef = (UInt32 *)&itemResult;
			if (FindEquipped(act, slot, &getObject, &itemResult)) // If we find nothing, there already is no equip
			{
				UnEquipItemCommand(act,*itemRef);
				RemoveOneItemQueue.push(pair<Actor *,UINT32>(act,*itemRef));
			}
		}
		
	}
	return true;
}

bool InjectAnimation( Entity *ent,BYTE slot,bool Playing )
{
	TESObjectREFR * refr = GetRefrFromEntity(ent);
	if(!refr || !refr->IsActor())
		return false;
	else
	{
		//TODO: rework this
		double result;
		// We wish to call PlayGroup. This has the parameters ( which are passed as flat array in arg1 ) 
		// AnimGroup ( a UINT16) , and 1 Integer ( flag, which we want to be "1" ) 
		UInt8 ParamData[sizeof(UINT16) + sizeof(UINT32)];
		Actor * actor = (Actor *)refr;
		// create a Script object
		UInt8	scriptObjBuf[sizeof(Script)];
		Script	* tempScriptObj = (Script *)scriptObjBuf;

		void	* scriptState = GetGlobalScriptStateObj();

		tempScriptObj->Constructor();
		tempScriptObj->MarkAsTemporary();
		if(Playing)
			*((UINT16 *)ParamData) = slot; // Set parameter 1 ( aniom group) 
		else 
			*((UINT16 *)ParamData) = 0; // Play idle anim
		*((UINT32 *)(ParamData + 2)) = 1; // Flag to start immediately
		// Parameter list, parameters, thisOBj, arg3= param count, ScriptEventList ( what to put in there?) , Result ptr, and offset ( is 0 ok ? ) 
		Cmd_PlayGroup_Execute(kParams_CmdPlayGroup,ParamData,actor, 2,tempScriptObj,NULL,&result,0); // NULL denotes incomplete params
		tempScriptObj->StaticDestructor();
	}
	return true;
}