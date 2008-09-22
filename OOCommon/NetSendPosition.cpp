/*

Copyright(c) 2007-2008   Julian Bangert aka masterfreek64
This file is part of OblivionOnline.

OblivionOnline is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

OblivionOnline is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Linking OblivionOnline statically or dynamically with other modules is making a combined work based
on OblivionOnline. Thus, the terms and conditions of the GNU General Public License cover 
the whole combination.

In addition, as a special exception, the copyright holders of  OblivionOnline give you permission to 
combine OblivionOnline program with free software programs or libraries that are released under
the GNU LGPL and with code included in the standard release of Oblivion Script Extender by Ian Patterson (OBSE)
under the OBSE license (or modified versions of such code, with unchanged license). You may copy and distribute such a system 
following the terms of the GNU GPL for  OblivionOnline and the licenses of the other code concerned,
provided that you include the source code of that other code when and as the GNU GPL
requires distribution of source code.

Note that people who make modified versions of  OblivionOnline are not obligated to grant this special exception
for their modified versions; it is their choice whether to do so. 
The GNU General Public License gives permission to release a modified version without this
exception; this exception also makes it possible to release a modified version which carries 
forward this exception.
*/
#include "OutPacket.h"
bool NetSendPosition(OutPacket *outnet, UINT32 FormID,BYTE Status,float PosX,float PosY,float PosZ,float RotX,float RotY,float RotZ )
{
	float Data[6] =
	{
		PosX,PosY,PosZ,RotX,RotY,RotZ
	};
	outnet->AddChunk(FormID,Status,GetMinChunkSize(Position),Position,(BYTE *)&Data);
	return true;
}
bool NetSendCellID(OutPacket *outnet, UINT32 FormID,BYTE Status,UINT32 CellID,bool IsInInterior )
{
	BYTE Data[5];
	*((UINT32 *)Data) = CellID;
	Data[4] = IsInInterior ? 1 : 0;
	outnet->AddChunk(FormID,Status,GetMinChunkSize(PkgChunk::CellID),PkgChunk::CellID,(BYTE *)&Data);
	return true;
}
bool NetSendAnimation(OutPacket *outnet,UINT32 FormID,BYTE Status,BYTE Animation,bool IsPlaying)
{
	BYTE Data[2]= 
	{
		Animation,
		(IsPlaying ? 1: 0)
	};
	outnet->AddChunk(FormID,Status,GetMinChunkSize(PkgChunk::Animation),PkgChunk::Animation,Data);
	return true;
}