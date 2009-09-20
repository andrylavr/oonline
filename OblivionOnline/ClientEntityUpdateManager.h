/*

Copyright(c) 2007-2009   Julian Bangert aka masterfreek64

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
#include "EntityUpdateManager.h"

class  ClientEntityUpdateManager : public EntityUpdateManager
{
public:
	ClientEntityUpdateManager(EntityManager * mgr) : EntityUpdateManager(mgr)
	{

	}
	OO_API virtual void OnPositionUpdate(Entity *ent,bool Inbound );//Triggers Events and network code;
	OO_API virtual void OnAVUpdate(Entity *ent,unsigned char AVCode,bool Inbound );
	OO_API virtual  void GlobalSend(Entity *ent,bool Inbound );
	OO_API virtual void OnNameUpdate(Entity *ent,bool Inbound );
	OO_API virtual void OnEquipUdate(Entity *ent,unsigned char slot,bool Inbound );
	OO_API virtual void OnClassUpdate(Entity *ent,bool Inbound );
	OO_API virtual void OnCellChange(Entity *ent,UINT32 oldCell, bool Inbound );
	OO_API virtual void OnRaceUpdate(Entity *ent,bool Inbound );
	OO_API virtual void OnGenderUpdate(Entity *ent,bool Inbound );
	OO_API virtual void OnAnimationUpdate(Entity *ent,unsigned char AnimationID,bool Inbound );
	OO_API virtual void Chat(Entity *ent,std::string Message,bool Inbound );
};