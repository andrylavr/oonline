#pragma once
/*

Copyright(c) 2007-2010   Julian Bangert 

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
*/
#include "Entity.h"
class NetworkBuffer;
class NetworkConnection  
{ 
	boost::mutex recvlock,sendlock;
	EntityManager *mgr;
	NetworkBuffer *recvtcp;
	NetworkBuffer *sendtcp;
	boost::condition_variable readytosend;
//	SOCKET udpsock;
	SOCKET tcpsock;
	ChunkPermissions permissions;
	FD_SET readSet;	
	FD_SET writeSet;
	int activechunk; // Number of active chunks, must be zero
	int chunks;
	void ParseInput(char *data,int datasize);
	bool Poll(); // Poll this network connection for any inbound traffic.
	bool Send();
public:
	boost::signal OnDisconnect;
	NetworkConnection(EntityManager *mgr,SOCKET tcp,boost::function1<void,NetworkConnection *> callback);
	~NetworkConnection(void);
	char *GetChunkSpace(bool Reliable,int size); // Only to be called from chunk constructor.
	void ChunkFinish();
	bool Process(); // Mostly poll and destroy if connection was dropped.
	const ChunkPermissions &GetPermissions() const {return permissions;}
};
class BadProtocolException :public  std::runtime_error
{
	BadProtocolException():std::runtime_error("An error was encountered parsing a packet.");
};
class ProtocolSecurityExcpetion : public std::runtime_error
{
	ProtocolSecurityExcpetion(NetworkConnection *who,PkgChunk t): std::runtime_error("A protocol security violation was detected. Unauthorized Chunk.");
};