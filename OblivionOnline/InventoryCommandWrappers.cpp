/*

Copyright(c) 2007-2010   Julian Bangert , Joseph Pearson aka chessmaster42

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
#include "CommandWrapper.h"
#include "GameCommand.h"
bool EquipItemCommand(Actor *thisObj,UINT32 FormID)
{
	TESObjectREFR *refr = (TESObjectREFR * ) LookupFormByID(FormID);
	if(!refr || !thisObj)
		return false;
	//TODO: Is Inventory Item?
	//TODO: rework this
	double result;
	// Call AddItem: 1 Pointer to the form
	TESForm * arg1 [2]= {
		refr,
		(TESObjectREFR *)0
	}; // Set parameter 1 ( Object) 
	// Parameter list, parameters, thisOBj, arg3= param count, ScriptEventList ( what to put in there?) , Result ptr, and offset ( is 0 ok ? ) 
	CallCmdExecuteGeneric(Cmd_EquipItem_Execute,kParams_CmdEquipItem,&arg1,2,thisObj,&result);
	return true;
}
bool UnEquipItemCommand(Actor *thisObj,UINT32 FormID)
{
	TESObjectREFR *refr = (TESObjectREFR * )LookupFormByID(FormID);

	if(!refr || !thisObj)
		return false;
	//TODO: Is Inventory Item?
	//TODO: rework this
	double result;
	// Call AddItem: 1 Pointer to the form
	TESObjectREFR * arg1[2]=
	{
		refr,
		(TESObjectREFR *)0
	}; //
	//arg1 = refr; // Set parameter 1 ( Object) 
	// Parameter list, parameters, thisOBj, arg3= param count, ScriptEventList ( what to put in there?) , Result ptr, and offset ( is 0 ok ? ) 
	CallCmdExecuteGeneric(Cmd_UnequipItem_Execute,kParams_CmdUnequipItem,&arg1,1,thisObj,&result);
	return true;
}
bool AddOneItemCommand(Actor *thisObj,UINT32 FormID)
{
	TESObjectREFR *refr = (TESObjectREFR * )LookupFormByID(FormID);
	if(!refr || !thisObj)
		return false;
	//TODO: Is Inventory Item?
	//TODO: rework this
	double result;
	TESObjectREFR * arg1[2] = 
	{
		refr,
		(TESObjectREFR *) 1
	}; 
	// Parameter list, parameters, thisOBj, arg3= param count, ScriptEventList ( what to put in there?) , Result ptr, and offset ( is 0 ok ? ) 
	CallCmdExecuteGeneric(Cmd_AddItem_Execute,kParams_CmdAddItem,&arg1, 1,thisObj,&result); // NULL denotes incomplete params
}
bool RemoveOneItemCommand(Actor * thisObj,UINT32 FormID)
{
	TESObjectREFR *refr = (TESObjectREFR *)LookupFormByID(FormID);
	if(!refr || !thisObj)
		return false;
	//TODO: Is Inventory Item?
	//TODO: rework this
	double result;
	// Call RemoveItem: 1 Pointer to the form, 1 Integer
	TESObjectREFR * arg1[2] = 
	{
		refr,
		(TESObjectREFR *) 1
	}; 
	// Parameter list, parameters, thisOBj, arg3= param count, ScriptEventList ( what to put in there?) , Result ptr, and offset ( is 0 ok ? ) 
	CallCmdExecuteGeneric(Cmd_RemoveItem_Execute,kParams_CmdRemoveItem,arg1, 1,thisObj,&result); // NULL denotes incomplete params

}