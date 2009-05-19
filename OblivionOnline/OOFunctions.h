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
#ifndef _OOFUNCTIONS_H
#define _OOFUNCTIONS_H
#include "main.h"
#include "GameClient.h"
#include "../OOCommon/Packets.h"
extern void RunScriptLine(const char *buf, bool IsTemp);
extern UINT32 GetPlayerNumberFromRefID(UInt32 refID);
extern GameClient * gClient;
inline int GetPlayerNumberFromSpawnNumber(USHORT SpawnNumber) 
{
	return ((SpawnNumber < gClient->GetLocalPlayer()) ? SpawnNumber : (SpawnNumber +1 ));
};

inline USHORT GetSpawnIDFromPlayerID(USHORT  PlayerID) // retrieves a player number from a refID in spawn
{
	return ((gClient->GetLocalPlayer() > PlayerID) ? PlayerID : (PlayerID -1));
};

inline UINT32 GetPlayerFormID(UINT32 PlayerID)
{
	if(PlayerID == gClient->GetLocalPlayer())
		return (*g_thePlayer)  ->refID;
	else
		return gClient->GetSpawnRefID(gClient->GetLocalPlayer() > PlayerID ? PlayerID : (PlayerID -1)); // TODO: Revamp this
}
inline bool IsPlayerSpawn(UINT32 RefID)
{
	for(int i = 0;i < MAXCLIENTS;i++)
	{
		if(gClient->GetSpawnRefID(i) == RefID)
			return true;
	}
	return false;
}
inline BYTE GetStatus(TESObjectREFR *refr)
{
	if(!refr->IsActor())
		return STATUS_OBJECT;
	if(IsPlayerSpawn(refr->refID))
		return STATUS_PLAYER;
	return STATUS_NPC;
}
#endif