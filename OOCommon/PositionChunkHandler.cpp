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
#include "ChunkHandler.h"
#include "InPacket.h"
#include "Entity.h"
#if 0
size_t ChunkHandler::HandlePositionChunk(EntityManager *entities,NetworkConnection *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	Entity *ent = entities->GetEntity(Status,FormID);
	float *floats = (float *)(chunkdata + 2);
	if(ent == NULL)
	{
		(*IO)<<Error<<"Error handling position chunk: Entity not registered"<< endl;
		return 0;
	}	
	//(*IO)<<GameMessage<<"Entity "<<FormID<<" updated its position to "<<floats[0]<<' '<<floats[1]<<' '<<floats[2]<<' '<<floats[3]<<' '<<floats[4]<<' '<<floats[5]<<"in cell "<<ent->CellID()<<endl;
	ent->MoveNRot(floats[0],floats[1],floats[2],floats[3],floats[4],floats[5],true);
	return GetMinChunkSize(Position) + sizeof(unsigned short);
}
size_t ChunkHandler::HandleCellIDChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	Entity *ent = entities->GetEntity(Status,FormID);
	if(ent == NULL)
	{
		(*IO)<<Error<<"Error handling CellID chunk: Entity not registered"<< endl;
		return 0;
	}	
	ent->SetCell(*(UINT32*)(chunkdata +2),(*(chunkdata + 6)) == 1,true);
	return GetMinChunkSize(CellID) + sizeof(unsigned short);
}

size_t ChunkHandler::HandleAnimationChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	BYTE AnimationID,AnimStatus;
	AnimationID = *(chunkdata + 2);
	AnimStatus = *(chunkdata +3);
	Entity *ent = entities->GetEntity(Status,FormID);
	if(ent == NULL)
	{
		(*IO)<<Error<<"Error handling Animation chunk: Entity not registered"<< endl;
		return 0;
	}	
	ent->SetAnimation(AnimationID,AnimStatus,true);
	//(*IO)<<LogLevel::SystemMessage<<"Animation State changed Entity : " << FormID<<" Status "<< (unsigned short)Status<< "animation "<< AnimationID << " On /Off " << AnimStatus;  
	return GetMinChunkSize(Animation) + sizeof(unsigned short);
}
#endif