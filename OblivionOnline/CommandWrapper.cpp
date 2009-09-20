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
void CallCmdExecuteGeneric(_Cmd_Execute Command,ParamInfo * paraminfo,void * paramdata,const unsigned int ParamCount,TESObjectREFR *thisobj,double *result)
{
	//We need to find an opcode for the command, "compile" our own script, generate opcodeoffsetpointer
	//(pointer to params - opcode  I think) and THEN pass the parameters. This is bullshit
	
	UInt32 opcodeoffset = 4;
	UInt8	scriptObjBuf[sizeof(Script)];
	Script	* tempScriptObj = (Script *)scriptObjBuf;
	ScriptEventList evt;
	void	* scriptState = GetGlobalScriptStateObj();
	tempScriptObj->Constructor();
	tempScriptObj->MarkAsTemporary();
	evt.m_eventList = NULL;
	evt.m_script = tempScriptObj;
	evt.m_vars = NULL;
	evt.m_unk1 = 0;
	Command(paraminfo,paramdata,thisobj,ParamCount,tempScriptObj,&evt,result,&opcodeoffset);
	tempScriptObj->StaticDestructor();
}