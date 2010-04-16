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
#pragma once
#ifndef GameInject_h__
#define GameInject_h__
class TESObjectREFR;
class ClientEntity;
TESObjectREFR *GetRefrFromEntity(ClientEntity * ent);
bool InjectActorValue(ClientEntity *ent,BYTE slot, INT16 value);
bool InjectEquip(ClientEntity *ent,BYTE slot,UINT32 formid);
bool InjectAnimation(ClientEntity  *ent,BYTE slot);
inline void SafeAddUpdateQueue(Entity * ent)
{	
	if(!gClient->GetUpdateQueue()->empty())
	{
		deque<Entity *>::iterator UpdateIterator;
		UpdateIterator =gClient->GetUpdateQueue()->begin();
		while(1)
		{
			if(UpdateIterator == gClient->GetUpdateQueue()->end())
				break; //really bad , but fixes some crashes ??
			if((*UpdateIterator) == ent )
				return;
			UpdateIterator++;
		}
	}
	gClient->GetUpdateQueue()->push_back(ent);
}
//Called every frame, BEFORE synch takes place, to fix up things
void InjectEquip_Handlebacklog();
#endif // GameInject_h__