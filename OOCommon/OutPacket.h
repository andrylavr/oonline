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
#include <string>
#include "GlobalDefines.h"
#include "Packets.h"
#include <ctime>
#if 0 
class OutPacket
{
private:
	BYTE m_Data[PACKET_SIZE];
	UINT32 m_ObjectID[MAX_OBJECTS_PER_PACKET];
	BYTE m_Status[MAX_OBJECTS_PER_PACKET];
	BYTE *m_Dataptr; 
	UINT16 *m_Bytes_written;
	UINT8 *m_Chunks_written;
	
	BYTE m_ObjectsWritten;
	bool m_Reliable;


	inline bool WriteByte(BYTE data)
	{
		if(*m_Bytes_written  < PACKET_SIZE) // m_Bytes_written + 1 <= tuned
		{
			*m_Dataptr = data;
			(*m_Bytes_written)++;
			m_Dataptr++;
			return true;
		}
		return false;
	}
	inline bool WriteWord(UINT16 data)
	{
		if(*m_Bytes_written + 1 < PACKET_SIZE)// m_Bytes_written + 2 <= tuned
		{
			*((UINT16 *)m_Dataptr) = data;
			(*m_Bytes_written) += sizeof(UINT16);
			m_Dataptr+=sizeof(UINT16);
			return true;
		}
		return false;
	}
	inline bool WriteUINT32(UINT32 data)
	{
		if(*m_Bytes_written + sizeof(UINT32) <= PACKET_SIZE)
		{
			*((UINT32 *)m_Dataptr) = data;
			(*m_Bytes_written) += sizeof(UINT32);
			m_Dataptr+=sizeof(UINT32);
			return true;
		}
		return false;
	}
	inline bool Write(size_t len,BYTE *data)
	{
		if(*m_Bytes_written + len <= PACKET_SIZE)
		{
			memcpy(m_Dataptr,data,len);
			(*m_Bytes_written) += len;
			m_Dataptr+=len;
			return true;
		}
		return false;
	}
	inline BYTE FindObjectID(UINT32 FormID,BYTE Status)
	{	
		for(BYTE i = 0;i < MAX_OBJECTS_PER_PACKET; i++)
		{
			if((m_Status[i] == STATUS_PLAYER) == (Status == STATUS_PLAYER) && m_ObjectID[i] == FormID)
				return i;
		}	
		return MAX_OBJECTS_PER_PACKET;
	}
	inline size_t RemainingDataSize()
	{
		return PACKET_SIZE - *m_Bytes_written;
	}
	inline BYTE GetObjectID(UINT32 FormID,BYTE Status)
	{		
		BYTE i = 0;		
		for(i = 0;i < m_ObjectsWritten; i++)
		{
			if(m_Status[i] == Status && m_ObjectID[i] == FormID)
				return i;
		}
		//write it
		if( RemainingDataSize() < (sizeof(UINT32) + 3))
			return MAX_OBJECTS_PER_PACKET;		//packet full
		//Search for a new slot
		if(m_ObjectsWritten == MAX_OBJECTS_PER_PACKET )
			return MAX_OBJECTS_PER_PACKET; // We found no empty slot
		i = m_ObjectsWritten;
		m_ObjectID[i] = FormID;
		m_Status[i] = Status;		
		WriteWord((   ((UINT16)Object)   & CHUNKMASK)|( (i<< 12) & OBJECTMASK));
		(*m_Chunks_written)++;
		WriteUINT32(FormID);
		WriteByte(Status);
		m_ObjectsWritten++;
		return i;
	}
public:
	clock_t SendTimer;
	OutPacket()
	{
		memset(m_ObjectID,0xffffffff,sizeof(UINT32)*MAX_OBJECTS_PER_PACKET);
		memset(m_Status,255,sizeof(bool)*MAX_OBJECTS_PER_PACKET);
		m_Dataptr = m_Data + PACKET_HEADER_SIZE;
		m_Bytes_written =  (UINT16 *)((UINT8 *)m_Data + 1); 
		m_Chunks_written = (UINT8 *)m_Data;
		*m_Bytes_written = PACKET_HEADER_SIZE;
		*m_Chunks_written = 0;
		m_Reliable = false;
		m_ObjectsWritten = 0;
		SendTimer = clock() + RESEND_TICK;
	}
	~OutPacket(void)
	{
	}
	inline void Reset()
	{
		/*memset(m_ObjectID,0xffffffff,sizeof(UINT32)*MAX_OBJECTS_PER_PACKET);
		memset(m_Status,255,sizeof(bool)*MAX_OBJECTS_PER_PACKET);*/
		memset(&m_Data,255,PACKET_SIZE);
		m_Dataptr = m_Data + PACKET_HEADER_SIZE;
		m_Bytes_written =  (UINT16 *)((UINT8 *)m_Data + 1); 
		m_Chunks_written = (UINT8 *)m_Data;
		*m_Bytes_written = PACKET_HEADER_SIZE;
		*m_Chunks_written = 0;
		m_Reliable = false;
		m_ObjectsWritten = 0;
		SendTimer = clock() + RESEND_TICK;
	}
	inline bool AddChunk(UINT32 FormID,BYTE Status,size_t ChunkSize,PkgChunk ,BYTE *data)
	{
		if(*m_Chunks_written >= 0xff) // TOO many chunks
			return false;
		if(RemainingDataSize() < ChunkSize + 2)  // Chunk Header
			return false; // No more space
		BYTE ObjectID = GetObjectID(FormID,Status);
		if( ObjectID == MAX_OBJECTS_PER_PACKET)
			return false; // TOO many objects or too less space
		WriteWord(((UINT16) & CHUNKMASK)|(ObjectID & OBJECTMASK));
		Write(ChunkSize,data);
		(*m_Chunks_written)++;
		if(RequiresReliable())
			m_Reliable = true;
		return true;
	}
	inline BYTE* GetData()
	{
		return m_Data;
	}
	inline bool Reliable()
	{
		return m_Reliable;
	}
	inline size_t Size()
	{
		return *m_Bytes_written;
	}
};
#endif