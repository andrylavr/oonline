#pragma once
#include "GlobalDefines.h"
#include "Packets.h"
#include <set>
#include <deque>
#include <boost/thread.hpp>
class NetworkBuffer;
class NetworkBufferManager
{
	static const int minbuffers = 100;
	boost::mutex _queuelock;
	static NetworkBufferManager _inst;
	std::set<NetworkBuffer *> _inuse;
	std::deque<NetworkBuffer *> _free;
public:
	NetworkBufferManager(void);
	~NetworkBufferManager(void);
	static NetworkBufferManager & Instance()
	{
		//if(!_inst) _inst =new NetworkBufferManager();
		return _inst;
	}
	void Release(NetworkBuffer * buffer);
	NetworkBuffer *GetNew();
};
class NetworkBuffer : public boost::mutex
{
	int refcount; // reference counter - passed out as pointer
	char data[PACKET_SIZE]; // data
	char *write;
	friend class NetworkBufferManager;
	NetworkBuffer();
	~NetworkBuffer();
public:
	void Release()
	{ 
		if(--refcount<=0){
			refcount=0;
			write=data;
			NetworkBufferManager::Instance().Release(this);
		}
	}
	void Acquire()
	{
		refcount++;
	}
	const char *GetData() const
	{
		return data;
	}
	size_t size() const
	{
		return sizeof(data);
	}
	size_t remaining() const
	{
		return data + sizeof(data) - write;
	}
	char *GetWrite(){return write;}
	void SetWrite(ptrdiff_t offset){write=data+offset;}
	void IncrementWrite(size_t add){assert(add <= remaining()); write+=add;}
};