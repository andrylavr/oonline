/*
This file is part of OblivionOnline Server- An open source game server for the OblivionOnline mod
Copyright (C)  2008   Julian Bangert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.


You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "Gameserver.h"
#include "ChunkHandler.h"
#include "Entity.h"
#include "NetworkSystem.h"
#include "InPacket.h"
size_t ChunkHandler::HandleChatChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	size_t retval;
	UINT16 supposedlength = *(unsigned short *)(chunkdata + 2);
	Entity *ent = entities->GetEntity(Status,FormID);
	std::string message = ent->Name();
	if(supposedlength > len - 4)
		retval = len;
	else
		retval = supposedlength;
	message.append(" :");
	message.append((char *)(chunkdata + 4),retval);
	*IO << PlayerChat << message << endl;
	for(map<UINT32,Entity *>::const_iterator i =  entities->GetPlayerList().begin(); i != entities->GetPlayerList().end() ; i++)
	{
		entities->GetUpdateMgr()->Chat(i->second,message,true);		
	}
	return retval + sizeof(unsigned short);
}
size_t ChunkHandler::HandleVersionChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	if(*(chunkdata + 2) == VERSION_SUPER && *(chunkdata+3) == VERSION_MAJOR && *(chunkdata+4) == VERSION_MINOR )
		(*IO)<<SystemMessage<<"Client "<<FormID <<" authenticated with the correct version" << endl;
	else
	{
		//TODO: kick him
		(*IO)<<SystemMessage<<"Client "<<FormID <<" tried to authenticate with an incorrect version:"<<*chunkdata<<*(chunkdata+1)<<*(chunkdata+2)<< endl;
	}
	return GetMinChunkSize(PkgChunk::Version) + sizeof(unsigned short);
}
size_t ChunkHandler::HandleClientTypeChunk(IOStream *IO,EntityManager *entities,InPacket *pkg,BYTE* chunkdata,size_t len,UINT32 FormID,BYTE Status)
{
	return GetMinChunkSize(PkgChunk::ClientType);
}
size_t ChunkHandler::HandlePlayerIDChunk(IOStream *IO,EntityManager*entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	return GetMinChunkSize(PkgChunk::PlayerID);
}