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
#pragma once
#include "GlobalDefines.h"
#include "ChunkHandler.h"
#include "IOSystem.h"
class EntityManager;
class InPacket
{
private:
	size_t m_streamlen;
	BYTE *m_stream;
	BYTE *m_current;
	IOStream *m_IO;
	EntityManager *m_entities;
	unsigned short m_currentchunk;
	unsigned short m_supposedsize;
	BYTE ChunkCount;
public:
	UINT32 ObjectIDs[16];
	BYTE Status[16];

	InPacket(EntityManager *entities,IOStream* IO,BYTE * stream,size_t streamlen)
	{
		m_stream = (BYTE*)malloc(streamlen);
		memcpy(m_stream,stream,streamlen); // So the stream can be released
		m_stream = m_stream;
		m_current = m_stream;
		m_currentchunk = 0;
		m_supposedsize = *(UINT16*)(m_stream+1);
		m_streamlen = streamlen;
		m_IO = IO;
		m_entities = entities;
		memset(ObjectIDs,0xffff,16*sizeof(UINT32));
		memset(Status,255,16);
	} 
	inline size_t HandleChunk(BYTE* chunkdata,BYTE* EndPtr )
	{
		PkgChunk chunk = GetChunkType(chunkdata);
		
		unsigned long maxsize = (unsigned long)EndPtr - (unsigned long)chunkdata;
		/*if(GetMinChunkSize(chunk) < maxsize )
			return false;*/
		UINT32 FormID = this->ObjectIDs[GetObject(chunkdata)];
		BYTE Status = this->Status[GetObject(chunkdata)];
		switch(chunk)
		{
		case	Object:
			return ChunkHandler::HandleObjectChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case	Position:
			return ChunkHandler::HandlePositionChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case CellID:
			return ChunkHandler::HandleCellIDChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		
		case Gender:
			return ChunkHandler::HandleGenderChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case Race:
			return ChunkHandler::HandleRaceChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case Class:
			return ChunkHandler::HandleClassChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case Name:
			return ChunkHandler::HandleNameChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case ActorValue:
			return ChunkHandler::HandleActorValueChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case Equip:
			return ChunkHandler::HandleEquipChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case Chat:
			return ChunkHandler::HandleChatChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case Auth:
			//return HandleAuthChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
			return GetMinChunkSize(Auth);
		case ClientType:
			return ChunkHandler::HandleClientTypeChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case Version:
			return ChunkHandler::HandleVersionChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case Animation:
			return ChunkHandler::HandleAnimationChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		case PlayerID:
			return ChunkHandler::HandlePlayerIDChunk(m_IO,m_entities,this,chunkdata,maxsize,FormID,Status);
		default:
			return 0;
		}
	} 
	void HandlePacket()
	{
		size_t retval;
		int i = 0;
		BYTE *m_end = m_stream + (m_streamlen > m_supposedsize ? m_supposedsize:m_streamlen);
		ChunkCount = m_stream[0];//The Data
		m_current += 3;
		for(;i < ChunkCount;i++)
		{
			if(m_current >= m_end)
			{
				
				return;
			}
			retval = HandleChunk(m_current,m_end);
			
			if(retval == 0)
			{
				(*m_IO)<<Warning<<"Ignoring rest of packet : Wasted Chunks " << (unsigned short)ChunkCount - i << " of "<< (unsigned short)ChunkCount << "Bytes : " << (unsigned short)m_streamlen << endl;
				return;
			}
			m_current += retval;
		}
		if(i != ChunkCount)
		{
			(*m_IO)<< Warning << "Bad Packet: Not all data encountered"<<endl;
		}

	}
	UINT8 GetNumberOfChunks()
	{
		return *(UINT8*)(m_stream);
	}
	~InPacket(void)
	{
		free(m_stream);
	}
};
