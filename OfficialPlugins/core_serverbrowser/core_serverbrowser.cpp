// core_serverbrowser.cpp : Defines the exported functions for the DLL application.
//

#include <boost/thread.hpp>

#include <string>
#include "GlobalDefines.h"
#include "PlayerManager.h"
#include "ExternInterface.h"
#include "GameServer.h"
#include "EventSystem.h"
#include "NetworkSystem.h"
#include "LuaSystem.h"
// {E80E6083-30FC-4dc2-910C-49A0795C9D8E}

static const GUID modid = 
{ 0xe80e6083, 0x30fc, 0x4dc2, { 0x91, 0xc, 0x49, 0xa0, 0x79, 0x5c, 0x9d, 0x8e } };
// {866E2CA7-79A7-4102-BDF9-12DC0A2C271C}
static const GUID versionid = 
{ 0x866e2ca7, 0x79a7, 0x4102, { 0xbd, 0xf9, 0x12, 0xdc, 0xa, 0x2c, 0x27, 0x1c } };
GameServer *g_gs;
static int Socket;
static std::string servername,serverdescription,serverowner,serveremail,serverurl;
void PlayerChange(struct sockaddr_in *addr)
{
	char databuf[1024];
	if(!g_gs || !Socket)
		return;
	sprintf(databuf,"p%u",g_gs->GetPlayerManager()->size());
	send(Socket,databuf,1024,0); //TODO: Handle return value
}
static void StartServerBrowser()
{
	//char* IP;
	struct sockaddr_in ooaddr;
	struct hostent * host;
	//TODO: When connection fails here, move into a seperate thread and then reconnect in increasing intervals
	//TODO: Handle connection failure
	Socket = socket(AF_INET,SOCK_STREAM,0);
	host = gethostbyname("serverlist.obliviononline.com");
	//For now we assume obliviononline.com:49001 
	if(host==NULL)
	{
		g_gs->GetIO() << Error << "Could not start Server list, serverlist.obliviononline.com not resolved" <<endl;
		return;
	}
	 memset(&ooaddr,0,sizeof(sockaddr_in));
	memcpy(&ooaddr.sin_addr,host->h_addr_list[0],host->h_length);
	ooaddr.sin_port = htons(49001);
	ooaddr.sin_family = AF_INET;
	//IP=inet_ntoa(ooaddr.sin_addr);
	if(connect(Socket,(sockaddr *)&ooaddr,sizeof(sockaddr_in)) ==-1)
	{
		g_gs->GetIO() << Error << "ServerList: Could not connect to host "<<host->h_name<<" error code: "<<errno <<endl;
		return;
	}
	//TODO: ADD config for this
	else
	{
		char databuf[1024];
		servername = g_gs->GetLua()->GetString("ServerName");
		serverowner = g_gs->GetLua()->GetString("ServerOwner");
		serverurl = g_gs->GetLua()->GetString("ServerURL");
		serverdescription = g_gs->GetLua()->GetString("ServerDescription");
		//TODO: Check inbound data somehow, mmaybe allow remote server start
		sprintf(databuf,"n%.99s",servername.c_str());
		send(Socket,databuf,1024,0);
		sprintf(databuf,"d%.375s",serverdescription.c_str());
		send(Socket,databuf,1024,0);
		sprintf(databuf,"u%.255s",serverurl.c_str());
		send(Socket,databuf,1024,0);
		sprintf(databuf,"e%.127s",serveremail.c_str());
		send(Socket,databuf,1024,0);
		sprintf(databuf,"o%.63s",serverowner.c_str());
		send(Socket,databuf,1024,0);
		sprintf(databuf,"m%u",MAX_PLAYERS);
		send(Socket,databuf,1024,0);
		sprintf(databuf,"v%u",VERSION_CODE);
		send(Socket,databuf,1024,0);
		g_gs->GetEventSys()->DefaultEvents.EventConnect.connect(PlayerChange);
		g_gs->GetEventSys()->DefaultEvents.EventDisconnect.connect(PlayerChange);
		g_gs->GetIO() << BootMessage<<"Server is being listed on list" <<endl;
		PlayerChange(NULL);
		/* TODO: check return values*/
	}
}
void OnShutdown()
{
	if(Socket)
		closesocket(Socket);
	g_gs = 0;
}
extern "C" __declspec(dllexport) PluginInfo * OnLoad(GameServer *gs,BYTE versionsuper,BYTE versionmajor ,BYTE versionminor)
{
	//TODO: create an API to allow callbacks
	//These comments in here should give a VERY quick overview over our extendibility system
	//If you find any bugs in the interface, please file a bug AND make a forum post
	//Do NOT rely on these bugs , because they will be fixed
	PluginInfo *retval = new PluginInfo();
	if(versionmajor != VERSION_MAJOR || versionminor != VERSION_MINOR || versionsuper != VERSION_SUPER)
	{
		// This is a version dependent plugin, break
		g_gs->GetIO() << FatalError << "Get a version of ServerBrowser compiled for your version of OO server" <<endl;
		return NULL;
	}
	//First, we fill out the important Plugin Info structure
	retval->modid = modid;
	retval->versionid = versionid;
	strcpy(retval->Name, "OblivionOnline Server Browser"); // most compilers cann0ot assign a static char to another...
	strcpy(retval->VersionName,"Version 1");
	strcpy(retval->Author,"Julian Bangert");
	retval->Version = 1;
	retval->shutdown = OnShutdown;
	g_gs = gs;
	gs->GetEventSys()->DefaultEvents.EventBoot.connect(StartServerBrowser);
	return retval;
}


