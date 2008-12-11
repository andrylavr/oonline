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
#include "Packets.h"
#include "InPacket.h"
#include "IOSystem.h"

size_t ChunkHandler::HandleActorValueChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	Entity *ent = entities->GetEntity(Status,FormID);
	if(ent == NULL)
	{
		(*IO)<<Error<<"Error handling actor value chunk: Entity not registered"<< endl;
		return 0;
	}	
	ent->SetActorValue(*(chunkdata+2),*(INT16 *)(chunkdata + 3),true);
	return GetMinChunkSize(PkgChunk::ActorValue) + sizeof(unsigned short);
}
size_t ChunkHandler::HandleGenderChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	Entity *ent = entities->GetEntity(Status,FormID);
	if(ent == NULL)
	{
		(*IO)<<Error<<"Error handling gender chunk: Entity not registered"<< endl;
		return 0;
	}	
	ent->SetFemale(*(chunkdata+2),true);
	return GetMinChunkSize(PkgChunk::Gender) + sizeof(unsigned short);
}
size_t ChunkHandler::HandleRaceChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	Entity *ent = entities->GetEntity(Status,FormID);
	if(ent == NULL)
	{
		(*IO)<<Error<<"Error handling race chunk: Entity not registered"<< endl;
		return 0;
	}	
	ent->SetRace(*(UINT32 *)(chunkdata + 2),true);
	return GetMinChunkSize(PkgChunk::Race) + sizeof(unsigned short);
}

size_t ChunkHandler::HandleClassChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len,UINT32 FormID,BYTE Status)
{
	Entity *ent = entities->GetEntity(Status,FormID);
	if(ent == NULL)
	{
		(*IO)<<Error<<"Error handling class chunk: Entity not registered"<< endl;
		return 0;
	}	
	ent->SetClassName(ReadANSIString(chunkdata + 2,len-2),true);
	return ent->ClassName().length() + 2 + sizeof(unsigned short);//TODO: think of more clever way to handle strings
}
size_t ChunkHandler::HandleNameChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	Entity *ent = entities->GetEntity(Status,FormID);
	if(ent == NULL)
	{
		(*IO)<<Error<<"Error handling name chunk: Entity not registered"<< endl;
		return 0;
	}	
	ent->SetName(ReadANSIString(chunkdata + 2,len-2),true);
	return ent->Name().length() + 2 + sizeof(unsigned short);
}
size_t ChunkHandler::HandleEquipChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{
	Entity *ent = entities->GetEntity(Status,FormID);
	if(ent == NULL)
	{
		(*IO)<<Error<<"Error handling Equip chunk: Entity not registered"<< endl;
		return 0;
	}	
	ent->SetEquip(*(BYTE*)(chunkdata + 2),*(UINT32 *)(chunkdata + 3),true);
	return GetMinChunkSize(PkgChunk::Equip)  + sizeof(unsigned short);
}