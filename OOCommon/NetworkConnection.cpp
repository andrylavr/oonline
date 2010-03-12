#include "NetworkConnection.h"
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

NetworkConnection::NetworkConnection( EntityManager *mgr,SOCKET tcp,boost::function1<void,NetworkConnection *> callback ):sendlock(),recvlock(),tcpsock(tcp),mgr(Manager),activechunk(0)
{
	FD_ZERO(&readSet);
	FD_ZERO(&writeSet);
	recvtcp = NetworkBufferManager::Instance().GetNew();
	sendtcp = NetworkBufferManager::Instance().GetNew();
	OnDisconnect	+=	boost::bind(callback,this);
}
NetworkConnection::~NetworkConnection(void)
{
	recvtcp->Release();
	sendtcp->Release();
}
NetworkConnection & NetworkConnection::operator<<( NetworkBuffer &nbuf )
{
	nbuf.Acquire();
	
	nbuf.Release();
}

bool NetworkConnection::Poll()
{
	timeval timeout =
	{
		0, // sec
		0 // millisec
	};
	FD_SET(tcpsock,&readSet);
	if(select(0,&readSet,NULL,NULL,&timeout)<0)
	{
		IOStream::Instance() << Error << "Error calling select()" << errno<<endl;
		return false;
	}
	if(FD_ISSET(tcpsock,&readSet))
	{
		boost::lock_guard<boost::mutex> lock(lock);
		FD_CLR(tcpsock,&readSet);
		int rc=recv(tcpsock,recvtcp->GetWrite(),recvtcp->size(),0);
		if(rc<0)	return false; //Socket closed, remov connection	
		char *end = ParseInput(recvtcp->GetData(),rc);
		ptrdiff_t misseddata = rc-(end-recvtcp->GetData());
		//TODO: introduce zero copy buffering here. Would this be worthwhile?
		memcpy(recvtcp->GetData(),end,misseddata);// If not all data was parsed, handle the rest
		recvtcp->SetWrite(misseddata);
	}
	if(FD_ISSET(tcpsock,&writeSet))
	{
		FD_CLR(tcpsock,&writeSet);
		if(chunks>0 &&activechunk<=0) //absolutely lag free polling: efficiency vs responsiveness ( more responsive if we wait)
		{
			return Send();
		}
	}
	return true;
}

bool NetworkConnection::Process()
{
	if(!Poll())
	{
		OnDisconnect();
		return false;
	}
	return true;
}

char * NetworkConnection::ParseInput( char *data,int datasize ) // returns last byte or NULL to drop connection
{
	char *end=data+datasize;
	assert(datasize > 0);
	try
	{
		while(data<end)
		{ 
			size_t offset = HandleChunk(this,mgr,reinterpret_cast<raw::Chunk *>(data),end);
			if(!offset){
				break; // Stop parsing this packet. ( Not enough data for all chunks )
			}
			data+=offset;
		}
	}
	catch (BadProtocolException &e)
	{
		return NULL;
	}
	return data;
}
char * NetworkConnection::GetChunkSpace( bool Reliable,int size )
{
	boost::lock_guard<boost::mutex> guard(sendlock);
	if(size > sendtcp->size())
	{
			return NULL;
	}
	if(size > sendtcp->remaining())
	{
		assert(chunks>0)
		while(activechunk > 0)
			readytosend.wait(guard);
		Send();
	}
	assert(size <= sendtcp->remaining());
	char *retval=sendtcp->GetWrite();
	sendtcp->IncrementWrite(size);
	return retval;
}

void NetworkConnection::ChunkFinish()
{
	boost::lock_guard<boost::mutex> guard(sendlock);
	assert(activechunk>0);
	assert(chunks>0);
	if(--activechunk == 0) readytosend.notify_all();
}
bool NetworkConnection::Send()
{
	//Send Data
	assert(activechunk<=0);
	assert(chunks>0);
	boost::lock_guard<boost::mutex> guard(sendlock);
	ptrdiff_t outsiz = sendtcp->GetWrite() - sendtcp->GetData();
	sendtcp->SetWrite(0); // Write is now the read pointer
	int rc = 0;
	while(outsiz!= rc)
	{
		outsiz -= rc;
		rc = send(tcpsock,sendtcp->GetWrite(),outsiz,0);
		if(rc<=0)
			return false;
		sendtcp->SetWrite(sendtcp->GetWrite() - sendtcp->GetData() + rc); // Increment by rc
	}
	sendtcp->SetWrite(0);
	chunks=0;
	activechunk=0;
	return true;
}