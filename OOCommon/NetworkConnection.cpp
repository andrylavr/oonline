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
#include "NetworkBuffer.h"
#include "IOSystem.h"
#ifdef WIN32
#define errno WSAGetLastError()
#endif
NetworkConnection::NetworkConnection( EntityManager *manager,SOCKET tcp,boost::function<void (NetworkConnection *)> callback,ChunkPermissions permissions):sendlock(),
	recvlock(),tcpsock(tcp),mgr(manager),activechunk(0),chunks(0),_permissions(permissions)
{
	recvtcp = NetworkBufferManager::Instance().GetNew();
	sendtcp = NetworkBufferManager::Instance().GetNew();
	OnDisconnect.connect(callback);
}
NetworkConnection::~NetworkConnection(void)
{
	recvtcp->Release();
	sendtcp->Release();
}
bool NetworkConnection::Poll()
{
	timeval timeout =
	{
		0, // sec
		0 // millisec
	};
	fd_set readSet;	
	fd_set writeSet;
	FD_ZERO(&readSet);
	FD_ZERO(&writeSet);
	FD_SET(tcpsock,&readSet);
	FD_SET(tcpsock,&writeSet);
	if(select(0,&readSet,&writeSet,NULL,&timeout)<0)
	{
		IOStream::Instance() << Error << "Error calling select()" << errno<<endl;
		return false;
	}
	if(FD_ISSET(tcpsock,&readSet))
	{
		boost::lock_guard<boost::mutex> guard(recvlock);
		FD_CLR(tcpsock,&readSet);
		int rc=recv(tcpsock,recvtcp->GetWrite(),recvtcp->size(),0);
		if(rc<0)	return false; //Socket closed, remov connection	
		char *end = const_cast<char *>(ParseInput(recvtcp->GetData(),rc)); //It does not point to const memory
		ptrdiff_t misseddata = rc-(end-recvtcp->GetData());
		//TODO: introduce zero copy buffering here. Would this be worthwhile?
		memcpy((void*)recvtcp->GetData(),end,misseddata);// If not all data was parsed, handle the rest
		recvtcp->SetWrite(misseddata);
	}
	if(FD_ISSET(tcpsock,&writeSet))
	{
		boost::lock_guard<boost::mutex> guard(sendlock);
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
	try
	{
		if(!Poll())
		{
			OnDisconnect(this);
			delete this; // VERY DANGEROUS !!
			return false;
		}
		return true;
	}
	catch(std::exception e)
	{
		IOStream::Instance() << Error << "An error occured while handling connection data!:"<< e.what()<<endl;
		try
		{
			OnDisconnect(this);
			delete this; // VERY DANGEROUS !!
			return false;
		}
		catch(std::exception x)
		{
			IOStream::Instance() << Error << "An error occured dropping a player connection! Server restart recommended! Error: "<<x.what()<<endl;
			return false;
		}
		catch(...)
		{
			IOStream::Instance() << Error << "Bad exception type dropping a player connection!"<<endl;
			return false;
		}
	}
	catch(...)
	{
		IOStream::Instance()<< Error<< "A non std:: exception occured handling connection data! Complain to the developers!"<<endl;
		return false;
	}
}

const char * NetworkConnection::ParseInput(const char *data,int datasize ) // returns last byte or NULL to drop connection
{
	const char *end=data+datasize;
	assert(datasize > 0);
	try
	{
		while(data<end)
		{ 
			size_t offset = HandleChunk(this,mgr,reinterpret_cast<const raw::Chunk *>(data),end);
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
char * NetworkConnection::GetChunkSpace( bool Reliable,unsigned int size )
{
	sendlock.lock();
	if(size > sendtcp->size())
	{
			return NULL;
	}
	if(size > sendtcp->remaining())
	{
		assert(chunks>0);
		assert(activechunk<=0);
		Send();
	}
	assert(size <= sendtcp->remaining());
	char *retval=sendtcp->GetWrite();
	sendtcp->IncrementWrite(size);
	activechunk++;
	chunks++;
	return retval;
}

void NetworkConnection::ChunkFinish()
{
	{
		assert(activechunk>0);
		assert(chunks>0);
		--activechunk;
		sendlock.unlock();
	}
}
bool NetworkConnection::Send()
//This procedure is not thread safe!
{
	//Send Data
	assert(activechunk<=0);
	assert(chunks>0);
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