#include "NetworkBuffer.h"

NetworkBuffer::NetworkBuffer(void)
{
	SetWrite(0);
}

NetworkBuffer::NetworkBuffer() :data(),refcount(0)
{

}
void NetworkBufferManager::Release( NetworkBuffer * buffer )
{
	assert(buffer->refcount <=0);
	boost::lock_guard<boost::mutex>(_queuelock);
	std::set<NetworkBuffer *>::iterator i = _inuse.find(buffer);
	assert(i!= _inuse.end());
	_inuse.erase(i);
	_free.push(buffer);
}

NetworkBuffer * NetworkBufferManager::GetNew()
{
	if(_free.empty()) _free.push(new NetworkBuffer);
	NetworkBuffer *retval = _free.front();
	assert(retval);
	retval->refcount = 1;
	_inuse.insert(retval);
	_free.pop();
	return retval;
}
NetworkBufferManager::NetworkBufferManager():_inuse(),_free(),_queuelock()
{
	boost::lock_guard<boost::mutex>(_queuelock);
	for(int i=0;i<minbuffers;i++)
		_free.push(new NetworkBuffer);
};