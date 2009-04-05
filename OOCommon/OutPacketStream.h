/*

Copyright(c) 2007-2008   Julian Bangert aka masterfreek64

This file is part of OblivionOnline.

OblivionOnline is free software; you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

OblivionOnline is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Linking OblivionOnline statically or dynamically with other modules is making a combined work based
on OblivionOnline. Thus, the terms and conditions of the GNU Affero General Public License cover 
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
The GNU Affero General Public License gives permission to release a modified version without this
exception; this exception also makes it possible to release a modified version which carries 
forward this exception.
*/
#include "OutPacket.h"
#include "IOSystem.h"

// Provides an abstract way to send data both via UDP and via TCP
class OutPacketStream
{
private:
	SOCKADDR_IN RemoteAddress;
	SOCKET SocketUDP;
	SOCKET SocketTCP;
	OutPacket packet;
	IOStream * IO;
public:	
	OutPacketStream(SOCKET SockTCP,SOCKADDR_IN SockAddr,IOStream * IOsystem) : packet()
	{
		RemoteAddress = SockAddr;
		SocketUDP = socket(AF_INET,SOCK_DGRAM,0);
		SocketTCP = SockTCP;
		IO = IOsystem;
	}
	~OutPacketStream()
	{
	}
	inline bool AddChunk(UINT32 FormID,BYTE Status,size_t ChunkSize,PkgChunk ChunkType,BYTE *data)
	{
		if(!packet.AddChunk(FormID,Status,ChunkSize,ChunkType,data))
		{
			Send();
			return true;
		}
		if(!packet.AddChunk(FormID,Status,ChunkSize,ChunkType,data))
		{
			*IO << Error << " Chunk couldn't be written into fresh packet " << ChunkType << endl;
			return false;
		}
		return true;
	}
	bool Send();
};