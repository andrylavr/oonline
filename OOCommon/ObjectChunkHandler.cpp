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
#include "Entity.h"
#include "ChunkHandler.h"
#include "InPacket.h"
size_t ChunkHandler::HandleObjectChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	//DO not advance the header - instead write the object data
	pkg->ObjectIDs[GetObjectIDFromObjChunk(chunkdata)] = *((UINT32 *)(chunkdata + 2));
	FormID =   *((UINT32 *)(chunkdata + 2));
	pkg->Status[GetObjectIDFromObjChunk(chunkdata)] = *(chunkdata + 2 +sizeof(UINT32));
	Status = *(chunkdata + 2 +sizeof(UINT32));
	if(entities->GetEntity(Status,FormID) == NULL)
	{
		new Entity(entities,FormID,Status,false,false);
	}
	return GetMinChunkSize(PkgChunk::Object) + sizeof(unsigned short);
}