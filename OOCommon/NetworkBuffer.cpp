#include <boost/foreach.hpp>
#include "NetworkBuffer.h"

NetworkBufferManager  NetworkBufferManager::_inst = NetworkBufferManager();
NetworkBuffer::NetworkBuffer() :data(),refcount(0)
{
	SetWrite(0);
}

NetworkBuffer::~NetworkBuffer()
{

}
void NetworkBufferManager::Release( NetworkBuffer * buffer )
{
	boost::lock_guard<boost::mutex> guard(_queuelock);

	assert(buffer->refcount <=0);
	std::set<NetworkBuffer *>::iterator i = _inuse.find(buffer);
	assert(i!= _inuse.end());
	_inuse.erase(i);
	_free.push_front(buffer);
}

NetworkBuffer * NetworkBufferManager::GetNew()
{
	boost::lock_guard<boost::mutex> guard(_queuelock);

	if(_free.empty()) _free.push_front(new NetworkBuffer);
	NetworkBuffer *retval = _free.front();
	assert(retval);
	retval->refcount = 1;
	_inuse.insert(retval);
	_free.pop_front();
	return retval;
}
NetworkBufferManager::NetworkBufferManager():_inuse(),_free(),_queuelock()
{
	boost::lock_guard<boost::mutex> guard(_queuelock);

	for(int i=0;i<minbuffers;i++)
		_free.push_front(new NetworkBuffer);
};

NetworkBufferManager::~NetworkBufferManager( void )
{
//	assert(_inuse.empty());
	BOOST_FOREACH(NetworkBuffer *buf,_free)
		delete buf;
}