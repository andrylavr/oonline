
/*

Copyright(c) 2007-2008   Julian Bangert aka masterfreek64

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

Linking OblivionOnline statically or dynamically with other modules is making a combined work based
on OblivionOnline. Thus, the terms and conditions of the GNU Affero General Public License cover 
the whole combination.

In addition, as a special exception, the copyright holders of  OblivionOnline give you permission to 
combine OblivionOnline program with free software programs or libraries that are released under
the GNU LGPL and with code included in the standard release of Oblivion Script Extender by Ian Patterson (OBSE)
under the OBSE license (or modified versions of such code, with unchanged license). You may copy and distribute such a system 
following the terms of the GNU GPL for  OblivionOnline and the licenses of the other code concerned,
provided that you include the source code of that other code when and as the GNU GPL
requires distribution of source code.

Note that people who make modified versions of  OblivionOnline are not obligated to grant this special exception
for their modified versions; it is their choice whether to do so. 
The GNU Affero General Public License gives permission to release a modified version without this
exception; this exception also makes it possible to release a modified version which carries 
forward this exception.
*/
#include "Entity.h"
#include "main.h"
#include "NetSend.h"
#include "outpacketstream.h"
#include <math.h>
#define MOVE_THRESHOLD 0.2
extern bool FindEquipped(TESObjectREFR* thisObj, UInt32 slotIdx, FoundEquipped* foundEquippedFunctor, double* result);
static void SendActorPosition(TESObjectREFR *act,Entity *ent)
{	
	if(abs(act->posX - ent->PosX())> MOVE_THRESHOLD || abs(act->posY - ent->PosY()) > MOVE_THRESHOLD
		|| abs(act->posZ - ent->PosZ()) > MOVE_THRESHOLD || abs(act->rotZ - ent->RotZ()) > MOVE_THRESHOLD
		|| abs(act->rotX - ent->RotX())>MOVE_THRESHOLD ||abs(act->rotY - ent->RotY()) > MOVE_THRESHOLD)
	{
		ent->SetCell(act->parentCell->refID,act->parentCell->worldSpace == NULL);
		ent->MoveNRot(act->posX,act->posY,act->posZ,act->rotX,act->rotY,act->rotZ);
	}
}
static void SendActorHealthOnly(Actor *act,Entity *ent)
{
	for(BYTE i = 8;i <= 10;i++) // Only 8;9;10
	{
		ent->SetActorValue(i,act->GetActorValue(i));
	}
}
static void SendActorValues(Actor *act,Entity *ent)
{
	ASSERT(ent);
	ASSERT(act);
	ent->SetActorValue(8,act->GetActorValue(8));
	ent->SetActorValue(9,act->GetActorValue(9));
	ent->SetActorValue(10,act->GetActorValue(10));
}
static void SendActorEquip(Actor *act,Entity *ent)
{
	feGetObject getObject;
	double itemResult;
	UInt32* itemRef = (UInt32*)&itemResult;
	for(BYTE i = 0; i <= 20; i++) // traverse Slots
	{
		if(i == 18 || i == 19 || i== 9 || i == 10 || i == 11 || i == 12 || i == 14) // These do not exist 
			continue;
		if (!FindEquipped(act, i, &getObject, &itemResult))
		{
			ent->SetEquip(i,0);
		}
		ent->SetEquip(i,*itemRef);
	}
}
static void SendActorAnimation(Actor *act,Entity *ent)
{
	ActorAnimData *animdata = GetActorAnimData(act);
	for(int i = 0;i < 43;i++)
	{
		ent->SetAnimation(i,animdata->FindAnimInRange(i));
	}
}
bool Cmd_MPSendActor_Execute (COMMAND_ARGS)
{
	Entity *ent;  // TODO: this seems to make problems, maybe use volatile?
	Actor *actor = NULL;
	BYTE Status;
	if(!gClient->GetIsInitialized() )
		return true;
	// A heavy command xD
	// 1 - send local player data up .
	// 2 - send health magicka and fatigue  + equip up.
	// if MC :
	// 2 - send up position , stat equip , etc of NPCs
	//(*g_thePlayer) is ignored
	ent = gClient->GetEntities()->GetEntity(STATUS_PLAYER,gClient->GetLocalPlayer());
	if(ent == NULL)
		ent = new Entity(gClient->GetEntities(),gClient->GetLocalPlayer(),STATUS_PLAYER);
	//gClient->GetServerStream()->Send(); // Prevent Lag
	SendActorPosition(*g_thePlayer,ent);
	SendActorValues(*g_thePlayer,ent);
	SendActorEquip(*g_thePlayer,ent);
	SendActorAnimation(*g_thePlayer,ent);
	//Health of the other players
 // contains crashes
	for(int i = 0;i < MAXCLIENTS ;i++)
	{
		if(gClient->GetSpawnID(i) != 0)
		{
			
			actor = (Actor *)LookupFormByID(gClient->GetSpawnID(i));
			if(!actor)
			{
				continue; 
			}
			ent =  gClient->GetEntities()->GetEntity(STATUS_PLAYER,i);
			if(ent == NULL)
				ent = new Entity( gClient->GetEntities(),i,STATUS_PLAYER);
			if(!ent)
			{
				gClient->GetIO() << Error << __FILE__ << " (line:)" << __LINE__ << " : Out of memory or allocation error. Continuing."<<endl;
				continue; // This means an entity was missed
			}
			//SendActorHealthOnly(actor,ent);
			SendActorValues(actor,ent); // This causes a crash!!!
		}
	}
	if(gClient->GetIsMasterClient())
	{
		//rewritten
		//Just check up on the cells all other players are in
		std::list <TESObjectCELL *> CellStack;
		CellStack.push_back((*g_thePlayer)->parentCell);
		for(int i = 0 ; i < MAXCLIENTS;i++)
		{
			bool bInsert = true;
			if(gClient->GetSpawnID(i))
			{
				TESObjectREFR *form = (TESObjectREFR *)LookupFormByID(gClient->GetSpawnID(i));
				if(!form)
					continue;
				// Look through the list
				std::list <TESObjectCELL *>::iterator it = CellStack.begin();
				std::list <TESObjectCELL *>::iterator end = CellStack.end();
				for(;it != end; ++it)
				{
					//if( (*it)->Compare(form->parentCell) )
					if(!form->parentCell ||  (*it)->refID == form->parentCell->refID )
					{
						bInsert = false;
						break;
					}
				}
				if(bInsert)
					CellStack.push_back(form->parentCell);
			}
		}
		//now we process each cell...
		for(std::list <TESObjectCELL *>::iterator i = CellStack.begin();i != CellStack.end(); i++)
		{
			BYTE Status;
			TESObjectCELL * Cell = *i;
			TESObjectCELL::ObjectListEntry * ListIterator = &Cell->objectList;		

			while(ListIterator) // Iterate the loopds
			{
				if(ListIterator->refr->IsActor())
					Status = STATUS_NPC; // We ignore player objects - so
				else
				{
					ListIterator = ListIterator->next; //TODO: Add syncing for non-actor objects
					continue;
				}

				if(GetPlayerNumberFromRefID(ListIterator->refr->refID) == -1) // Do not synchronise objects used by OblivionOnline
				{
					ent = gClient->GetEntities()->GetEntity(Status,ListIterator->refr->refID);
					
					if(ent == NULL)
						ent = new Entity(gClient->GetEntities(),ListIterator->refr->refID,Status);
					//Sync that object too
					/*
					if(ListIterator->refr->parentCell->refID != ent->CellID)
					{
						ent->CellID = ListIterator->refr->parentCell->refID;
						NetSendCellID(ListIterator->refr->refID,Status,ent->CellID);
					} */
					SendActorPosition(ListIterator->refr,ent);					
					if(Status == STATUS_NPC)
					{
						Actor * actor = (Actor *)LookupFormByID(ListIterator->refr->refID);
						SendActorValues(actor,ent);
						SendActorEquip(actor,ent);
						SendActorAnimation(actor,ent);						
					}
				}
				ListIterator = ListIterator->next;
			}
		}
	}
	gClient->GetServerStream()->Send();
	return true;
}


CommandInfo kMPSendActorCommand =
{
	"MPSendActor",
	"MPSP",
	0,
	"Sends out data - long long routine",
	0,		// requires parent obj
	0,		// doesn't have params
	NULL,	// no param table
	Cmd_MPSendActor_Execute
};
