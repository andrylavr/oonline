#include "InNetStream.h"

InNetStream::InNetStream(IOStream *io,unsigned short port)
{
	sockaddr_in listenaddr;
	sock = socket(AF_INET,SOCK_DGRAM,0);

	if(sock == SOCKET_ERROR)
	{
		*io << FatalError << "Couldn't open UDP socket" << endl;
		exit(-1);
	}
	memset(&listenaddr,0,sizeof listenaddr);
	listenaddr.sin_family = AF_INET;
	listenaddr.sin_port = htons(port);
	listenaddr.sin_addr.s_addr = INADDR_ANY;
	if(bind(sock,(SOCKADDR *)&listenaddr,sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		*io <<Error<<"Could not bind UDP"<<endl;
		exit(-2);
	}
	else
		*io <<BootMessage<<"UDP Bound to port "<<port <<endl;
}

InNetStream::~InNetStream(void)
{
}
