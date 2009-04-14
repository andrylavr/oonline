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