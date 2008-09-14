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
#include "Packets.h"
class InPacket;
class EntityManager;
class IOStream;
size_t HandleObjectChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandlePositionChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandleChatChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandleCellIDChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandleVersionChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandleNameChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandleClassChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len,UINT32 FormID,BYTE Status);
size_t HandleRaceChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandleGenderChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandleSkillChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandleStatChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandleActorValueChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandleEquipChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);
size_t HandleAnimationChunk(IOStream *IO,EntityManager *entities,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE Status);