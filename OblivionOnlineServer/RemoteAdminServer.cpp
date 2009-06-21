#include "RemoteAdminServer.h"
#include "RemoteAdminModule.h"
#include "CoreAdminModules.h"
#include <list>
#include <string>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/algorithm.hpp>
#include "LuaSystem.h"
#ifdef WIN32
#include <process.h>
#include <Windows.h>
#else
#include <errno.h>
#include <pthread.h>
#endif
RemoteAdminServer::RemoteAdminServer(GameServer *gs) : transmit(),modules(),Header(),Footer()
{
	m_GS = gs;
	Header = "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\"><html xmlns=\"http://www.w3.org/1999/xhtml\"><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\" /><title>Remote Admin for ";
	Header += gs->GetLua()->GetString("Name");
	Header += "</title></head><body><p align=\"center\"><strong>OblivionOnline Remote Administrator @";
	Header += gs->GetLua()->GetString("Name");
	Header += "</strong></p><table width=\"100%\" border=\"1\"> <tr> <td width=\"150\" align=\"left\"><ul>";
	Middle = "</ul></td><td>";
	Footer = "</td></tr></table> <a href=\"http://obliviononline.com/\">OblivionOnline (C) 2006-2008 Julian Bangert </a></body></html>";
	RegisterModule(new ModuleAdminModule(gs));
	RegisterModule(new PlayerAdminModule(gs));
	#ifdef WIN32
	_beginthread(RemoteAdminServer::RunServer,0,this);
	#else
	pthread_t thread;
	pthread_create(&thread,NULL,RemoteAdminServer::RunServer,this);
	#endif
}

RemoteAdminServer::~RemoteAdminServer(void)
{
}
void RemoteAdminServer::Listen(unsigned short port,bool Global)
{
	char data[4096];
	acceptSocket = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addr;
	FD_SET fdSet;
	long rc;
	memset(&addr,0,sizeof(SOCKADDR_IN));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	m_GS->GetIO() << BootMessage << "Loading Remote Admin Server";
	if(Global)
		addr.sin_addr.s_addr = INADDR_ANY;
	else
		addr.sin_addr.s_addr= inet_addr("127.0.0.1");
	rc = bind(acceptSocket,(SOCKADDR*)&addr,sizeof(SOCKADDR_IN));
	if( rc == SOCKET_ERROR)
	{
		m_GS->GetIO()<<FatalError<<"Couldn't bind TCP on Remote Admin"<< endl;
		return ;
	}
	rc = listen(acceptSocket,4);
	if(rc == SOCKET_ERROR)
	{

		m_GS->GetIO()<<FatalError<<"Couldn't listen on TCP on Remote Admin"<<endl;
		return ;
	}
	else
	{
		
		m_GS->GetIO()<<BootMessage<<"TCP listening on Remote Admin"<<endl;
	}
	
	while(1)
	{
		FD_ZERO(&fdSet);
		FD_SET(acceptSocket,&fdSet);
		for(std::list<SOCKET >::iterator iter = transmit.begin() ;iter != transmit.end();iter++)
		{
			FD_SET(*iter,&fdSet);
		}
		if(select(0,&fdSet,NULL,NULL,NULL) == SOCKET_ERROR)
		{
			m_GS->GetIO()<<FatalError<<"Error calling select() on Remote Admin"<<errno<< endl;
			return;
		}
		if(FD_ISSET(acceptSocket,&fdSet))
		{
			SOCKADDR_IN addr;
#ifndef WIN32 
			socklen_t addr_size; 
#else		  
			int addr_size;
#endif	 
			addr_size = sizeof(SOCKADDR_IN);			
			SOCKET  sock = accept(acceptSocket,(SOCKADDR *)&addr,&addr_size);
			transmit.push_back(sock);
		}
		for(std::list<SOCKET >::iterator iter = transmit.begin() ;iter != transmit.end();iter++)
		{
			if(FD_ISSET(*iter,&fdSet))
			{
				rc = recv(*iter,(char *)data,4096,0);
				data[4095] = '\0';
				if(rc && rc!=SOCKET_ERROR)
				{		
					// Now we handle the data
					Process(data,rc,*iter);
					closesocket(*iter);
					transmit.erase(iter);
					break;
				}	
			}
		}
		
	}
}

void RemoteAdminServer::Process(char *data, unsigned long len, SOCKET sock)
{
	RemoteAdminModule * mod;
	char module[128];
	std::list<std::string> parameters;
	std::string current;
	int i = 0;
	int p = 4;
	for(; i < 127 && !isspace(data[p]) && data[p] != ',' ; i++,p++)
		module[i] = data[p];
	module[i] = 0;
	parameters.clear();
	if(!isspace(data[p])) // we are not parametr
	{
		while(p < len)
		{
			p++;
			if(!data[p])
				break;
			if(isspace(data[p]))
				break;
			if(data[p] == ',')
			{
				parameters.push_back(current);
				current = "";
				continue;
			}
			current += data[p];
		}
		parameters.push_back(current);
	}
	mod = FindModule(std::string(module));
	//std::map<SOCKADDR_IN,RemoteAuthInfo *>::const_iterator iter = modules.find(
	std::string Data = Header + Menu + Middle;
	std::string HTTP;
	if(!mod)
	{
		Data += "<b>Module not found</b>";
	}
	else
	{
		std::string *ptr = mod->GetData(&parameters);
		Data += *ptr;
		delete ptr;
	}
	Data+= Footer;
	HTTP = "HTTP/1.1 200 OK\nServer: OblivionOnlineRemoteAdmin\n\n" +  Data;
	const char  *dat = HTTP.c_str(); // send out data in a loop
	len = HTTP.length();
	unsigned long rc; 
	while(len)
	{
		rc = send(sock,dat,len,0);
		if(!rc)
			m_GS->GetIO() << Error << "Error Sending out Remote admin message " <<endl;
		len -= rc;
		dat += rc;
	}

}
RemoteAdminModule * RemoteAdminServer::FindModule(std::string name)
{
	if(name.length() < 2)
		return NULL; // The empty module is never found
	for(std::list<RemoteAdminModule *>::iterator iter = modules.begin();iter!=modules.end();iter++)
	{
		if(!strcmp((*iter)->GetName(),name.c_str() + 1) )//We need to remove the trailing slash
			return *iter;
	}
	return NULL;
}
OO_TPROC_RET RemoteAdminServer::RunServer(void *thisptr)
{
	RemoteAdminServer *server = (RemoteAdminServer *) thisptr;
	server->Listen(5000,true);
}
void RemoteAdminServer::RegisterModule(RemoteAdminModule *mod)
{
	modules.push_back(mod);
	if(mod->ShowInMenu())
	{
		Menu += "<li><a href=\"";
		Menu += mod->GetName();
		Menu += "\">";
		Menu += mod->GetDisplayName();
		Menu +="</a></li>";
	}
}
