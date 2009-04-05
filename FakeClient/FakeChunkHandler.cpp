///*
//Copyright 2008   Julian Bangert aka masterfreek64
//This file is part of OblivionOnline.
//
//OblivionOnline is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 3 of the License, or
//(at your option) any later version.
//
//OblivionOnline is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.
//*/
#include "InPacket.h"
#include "ChunkHandler.h"
#include "FakeClient.h"
size_t ChunkHandler::HandleChatChunk(IOStream *IO,EntityManager *entities,InPacket *packet, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{ 
	(*IO) << Chat << (char *)(chunkdata +2 + sizeof(unsigned short));
	return (sizeof(unsigned short)+ sizeof(unsigned short) + sizeof(unsigned short) + (len < *(unsigned short *)(chunkdata +2) ) ? (len) : *(unsigned short *)(chunkdata +2));
}
size_t ChunkHandler::HandlePlayerIDChunk(IOStream *IO,EntityManager*entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	g_fake->SetPlayerID(*(UINT32 *)(chunkdata + 2));
	*IO << GameMessage << "Player No " << *(UINT32 *)(chunkdata + 2) << endl;
	//NetSendName(outnet.GetPacket(),gClient->GetLocalPlayer(),STATUS_PLAYER,(BYTE *)(*g_thePlayer)->GetName(),strlen((*g_thePlayer)->GetName()));
	return GetMinChunkSize(PlayerID) + sizeof(unsigned short);
}
size_t ChunkHandler::HandleClientTypeChunk(IOStream *IO,EntityManager*entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	if((chunkdata + 2) > 0)
	{
		g_fake->SetIsMasterClient(true);
		g_fake->GetIO() << BootMessage << " Received Master Client" <<endl;
	}
	else
	{
		g_fake->SetIsMasterClient(false);
		g_fake->GetIO() << BootMessage << " Received Passive Client" <<endl;
	}
	return GetMinChunkSize(ClientType) + sizeof(unsigned short);
}
size_t ChunkHandler::HandleVersionChunk(IOStream *IO,EntityManager*entities,InPacket *pkg,BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	return GetMinChunkSize(PkgChunk::Version) + sizeof(unsigned short);
}