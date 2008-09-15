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
#include "UserInterface.h"
size_t HandleChatChunk(IOStream *IO,EntityManager*entities, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status)
{ 
	(*IO) << (char *)(chunkdata +2 + sizeof(unsigned short));
	RegisterChatMessage((char *)(chunkdata +2+ sizeof(unsigned short)));
	return (sizeof(unsigned short)+ sizeof(unsigned short) + sizeof(unsigned short) + (len < *(unsigned short *)(chunkdata +2) ) ? (len) : *(unsigned short *)(chunkdata +2));
}