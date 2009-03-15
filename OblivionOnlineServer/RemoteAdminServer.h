#pragma once
#ifdef WIN32 
#include <Windows.h>
#endif
#include <list>
#include "GameServer.h"
class RemoteAdminModule;
enum AuthLevel{
	Anonymous= 0,
	Mod,
	Admin
};
struct RemoteAuthInfo{
	SOCKADDR_IN addr;	
	std::string Username;
	AuthLevel authlevel;
	UINT64 SessionTicket;
	std::map<std::string,std::string> UserValues;
	time_t overflow;
};
class RemoteAdminServer
{
private:
	SOCKET acceptSocket;
	std::list<SOCKET > transmit;
	std::list<RemoteAdminModule *>modules;
	std::map <SOCKADDR_IN,RemoteAuthInfo *> authentifiedusers;
	GameServer *m_GS;
	std::string Header,Middle,Footer,Menu; //Header : Before Menu
	void Process(char *data,unsigned long len,SOCKET sock);
	
	RemoteAuthInfo *GetAuthinfo(SOCKADDR_IN *addr,UINT64 sessid);
	//Middle Between menu and Module
	//Footer: After it
public:
	RemoteAdminServer(GameServer *gs);
	~RemoteAdminServer(void);
	void Listen(unsigned short port,bool Global);
	void RegisterModule(RemoteAdminModule * mod);
	static OO_TPROC_RET RunServer(void *thisptr);
	RemoteAdminModule * FindModule(std::string Name);
};

