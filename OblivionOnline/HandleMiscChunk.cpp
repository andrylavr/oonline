/*

Copyright(c) 2007-2010   Julian Bangert 
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
#include "InPacket.h"
#include "ChunkHandler.h"
#include "UserInterface.h"
#include "NetSend.h"
#include "../OOCommon/InPacket.h"
#include "GameAPI.h"
size_t ChunkHandler::HandleVersionChunk(IOStream *IO,EntityManager*entities,InPacket *pkg,BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	if(*(chunkdata + 2) == VERSION_SUPER && *(chunkdata+3) == VERSION_MAJOR && *(chunkdata+4) == VERSION_MINOR )
		gClient->GetIO() <<  BootMessage << "Server using the same version as the client" << endl ;
	else
	{
		gClient->GetIO() <<Error << "Incorrect Server Version " << *(chunkdata + 2) << "." << *(chunkdata +3) << "." <<*(chunkdata + 4) << endl;
	}
	if(*(chunkdata + 5) != GAME_OBLIVION)
	{
		gClient->GetIO() <<Error << "Server is not hosting an Oblivion game" <<*(chunkdata + 4) << endl;
	}
	return GetMinChunkSize(PkgChunk::Version) + sizeof(unsigned short);
}
size_t ChunkHandler::HandlePlayerIDChunk(IOStream *IO,EntityManager*entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	gClient->SetPlayerID(*(UINT32 *)(chunkdata + 2));
	*IO << GameMessage << "Player No " << gClient->GetLocalPlayer() << endl;
	if(bUIInitialized)
		SetConnectionMessage("Good to go");
	//NetSendName(outnet.GetPacket(),gClient->GetLocalPlayer(),STATUS_PLAYER,(BYTE *)(*g_thePlayer)->GetName(),strlen((*g_thePlayer)->GetName()));
	return GetMinChunkSize(PlayerID) + sizeof(unsigned short);
}
size_t ChunkHandler::HandleClientTypeChunk(IOStream *IO,EntityManager*entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	if((chunkdata + 2) > 0)
	{
		gClient->SetIsMasterClient(true);
		gClient->GetIO() << GameMessage<<" Received Master Client" <<endl;
		Console_Print("Master Client");
	}
	else
	{
		gClient->SetIsMasterClient(false);
		gClient->GetIO() << GameMessage << "Received Passive Client" << endl;
		Console_Print("Passive Client");
	}
	return GetMinChunkSize(ClientType) + sizeof(unsigned short);
}