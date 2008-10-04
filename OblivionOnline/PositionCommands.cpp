/*

Copyright(c) 2007-2008   Julian Bangert aka masterfreek64
This file is part of OblivionOnline.

OblivionOnline is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

OblivionOnline is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Linking OblivionOnline statically or dynamically with other modules is making a combined work based
on OblivionOnline. Thus, the terms and conditions of the GNU General Public License cover 
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
The GNU General Public License gives permission to release a modified version without this
exception; this exception also makes it possible to release a modified version which carries 
forward this exception.
*/
#include "main.h"
#include "Entity.h"
bool Cmd_MPGetPosX_Execute (COMMAND_ARGS)
{
	if(gClient->GetIsInitialized())
		return true;
	if (!thisObj)
	{
		Console_Print("Error, no reference given for MPGetPosX");
		return true;
	}
	Entity *ent = gClient->GetEntities()->GetEntity(thisObj->refID,GetStatus(thisObj));
	*result = ent->PosX();
	return true;
}

bool Cmd_MPGetPosY_Execute (COMMAND_ARGS)
{
	if(gClient->GetIsInitialized())
		return true;
	if (!thisObj)
	{
		Console_Print("Error, no reference given for MPGetPosY");
		return true;
	}
	Entity *ent = gClient->GetEntities()->GetEntity(thisObj->refID,GetStatus(thisObj));
	*result = ent->PosY();
	return true;
}

bool Cmd_MPGetPosZ_Execute (COMMAND_ARGS)
{
	if(gClient->GetIsInitialized())
		return true;
	if (!thisObj)
	{
		Console_Print("Error, no reference given for MPGetPosZ");
		return true;
	}
	Entity *ent = gClient->GetEntities()->GetEntity(thisObj->refID,GetStatus(thisObj));
	*result = ent->PosZ();
	return true;
}

bool Cmd_MPGetRotZ_Execute (COMMAND_ARGS)
{
	if(gClient->GetIsInitialized())
		return true;
	if (!thisObj)
	{
		Console_Print("Error, no reference given for MPGetRotZ");
		return true;
	}
	Entity *ent = gClient->GetEntities()->GetEntity(thisObj->refID,GetStatus(thisObj));
	*result = ent->RotZ();
	return true;
}
bool Cmd_MPGetRotY_Execute (COMMAND_ARGS)
{
	if(gClient->GetIsInitialized())
		return true;
	if (!thisObj)
	{
		Console_Print("Error, no reference given for MPGetRotY");
		return true;
	}
	Entity *ent = gClient->GetEntities()->GetEntity(thisObj->refID,GetStatus(thisObj));
	*result = ent->RotY();
	return true;
}
bool Cmd_MPGetRotX_Execute (COMMAND_ARGS)
{
	if(gClient->GetIsInitialized())
		return true;
	if (!thisObj)
	{
		Console_Print("Error, no reference given for MPGetRotX");
		return true;
	}
	Entity *ent = gClient->GetEntities()->GetEntity(thisObj->refID,GetStatus(thisObj));
	*result = ent->RotX();
	return true;
}
bool Cmd_MPGetIsInInterior_Execute (COMMAND_ARGS)
{
	if(!gClient->GetIsInitialized())
		return true;
	if (!thisObj)
	{
		Console_Print("Error, no reference given for MPGetIsInterior");
		return true;
	}
	Entity *ent = gClient->GetEntities()->GetEntity(thisObj->refID,GetStatus(thisObj));
	//TESObjectCELL *obj = (TESObjectCELL *)Oblivion_DynamicCast(LookupFormByID(ent->CellID),0,RTTI_TESForm,RTTI_TESObjectCELL,0);	
	*result = ent->IsInInterior() ? 1 : 0;
	return true;
}


bool Cmd_MPGetCell_Execute (COMMAND_ARGS)
{
	if(!gClient->GetIsInitialized())
		return true;
	if (!thisObj)
	{
		Console_Print("Error, no reference given for MPGetCell");
		return true;
	}
	Entity *ent = gClient->GetEntities()->GetEntity(thisObj->refID,GetStatus(thisObj));
	*(UINT32 *) result = ent->CellID();
	return true;
}

CommandInfo kMPGetIsInInteriorCommand =
{
	"MPGetIsInInterior",
	"MPGIII",
	0,
	"Get IsInterior of an objects supposed parent cell",
	0,		// requires parent obj
	0,		// doesn't have params
	NULL,	// no param table
	Cmd_MPGetIsInInterior_Execute
};

CommandInfo kMPGetPosXCommand =
{
	"MPGetPosX",
	"MPGPX",
	0,
	"Gets an objects X position",
	0,		// requires parent obj
	0,		// has no param
	NULL,	// has no param table
	Cmd_MPGetPosX_Execute
};

CommandInfo kMPGetPosYCommand =
{
	"MPGetPosY",
	"MPGPY",
	0,
	"Gets an objects Y position",
	0,		// requires parent obj
	0,		// has no param
	NULL,	// has no param table
	Cmd_MPGetPosY_Execute
};

CommandInfo kMPGetPosZCommand =
{
	"MPGetPosZ",
	"MPGPZ",
	0,
	"Gets an objects Z position",
	0,		// requires parent obj
	0,		// has no param
	NULL,	// has no param table
	Cmd_MPGetPosZ_Execute
};

CommandInfo kMPGetRotZCommand =
{
	"MPGetRotZ",
	"MPGRZ",
	0,
	"Gets an objects Z rotation",
	0,		// requires parent obj
	0,		// has no param
	NULL,	// has no param table
	Cmd_MPGetRotZ_Execute
};
CommandInfo kMPGetRotYCommand =
{
	"MPGetRotY",
	"MPGRY",
	0,
	"Gets an objects Y rotation",
	0,		// requires parent obj
	0,		// has no param
	NULL,	// has no param table
	Cmd_MPGetRotY_Execute
};
CommandInfo kMPGetRotXCommand =
{
	"MPGetRotX",
	"MPGRX",
	0,
	"Gets an objects X rotation",
	0,		// requires parent obj
	0,		// has no param
	NULL,	// has no param table
	Cmd_MPGetRotX_Execute
};
CommandInfo kMPGetCellCommand =
{
	"MPGetCell",
	"MPGCL",
	0,
	"Gets an objects cell",
	0,		// requires parent obj
	0,		// has no param
	NULL,	// has no param table
	Cmd_MPGetCell_Execute
};
