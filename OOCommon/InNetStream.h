#pragma once
#include "GlobalDefines.h"
class InNetStream
{
public:
	InNetStream(IOStream *IO, unsigned short portnumber);
	~InNetStream(void);
protected:
	SOCKET *sock;
	IOStrem *io;
};
