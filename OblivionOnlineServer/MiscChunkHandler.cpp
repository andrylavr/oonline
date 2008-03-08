/*
OblivionOnline Server- An open source game server for the OblivionOnline mod
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
#include "InPacket.h"
size_t HandleChatChunk(GameServer *gs,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE status)
{
	//TODO : handle chat
	return true;
}
size_t HandleVersionChunk(GameServer *gs,InPacket *pkg, BYTE* chunkdata,size_t len ,UINT32 FormID,BYTE status)
{
	if(*(chunkdata + 2) == VERSION_SUPER && *(chunkdata+3) == VERSION_MAJOR && *(chunkdata+4) == VERSION_MINOR )
		gs->GetIO()<<GameMessage<<"Client "<<FormID <<" authenticated with the correct version" << endl;
	else
	{
		//TODO: kick him
		gs->GetIO()<<"Client "<<FormID <<" tried to authenticate with an incorrect version:"<<*chunkdata<<*(chunkdata+1)<<*(chunkdata+2)<< endl;
	}
	return true;
}