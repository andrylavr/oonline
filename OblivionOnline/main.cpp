/*

Copyright(c) 2007-2009   Julian Bangert aka masterfreek64, Joseph Pearson aka chessmaster42

This file is part of OblivionOnline.

    OblivionOnline is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    OblivionOnline is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Linking OblivionOnline statically or dynamically with other modules is making a combined work based
	on OblivionOnline. Thus, the terms and conditions of the GNU General Public License cover 
	the whole combination.

    In addition, as a special exception, the copyright holders of  OblivionOnline give you permission to 
	combine OblivionOnline program with free software programs or libraries that are released under
	the GNU LGPL and with code included in the standard release of Oblivion Script Extender by Ian Patterson (OBSE)
	under the OBSE license (or modified versions of such code, with unchanged license). You may copy and distribute such a system 
	following the terms of the GNU GPL for  OblivionOnline and the licenses of the other code concerned,
	provided that you include the source code of that other code when and as the GNU GPL
	requires distribution of source code.

	Note that people who make modified versions of  OblivionOnline are not obligated to grant this special exception
	for their modified versions; it is their choice whether to do so. 
	The GNU General Public License gives permission to release a modified version without this
	exception; this exception also makes it possible to release a modified version which carries 
	forward this exception.
*/
#include "main.h"
#include "UserInterface.h"
#include "D3Dhook.h"
#include "InPacket.h"
#include "Commands.h"
#include "ClientEntity.h"
#include "LogIOProvider.h"
#include "../OOCommon/InPacket.h"
#include "GameClient.h"
// Global variables
extern "C" HINSTANCE OODll;
GameClient *gClient = NULL;
IDebugLog		gLog;
PluginHandle gPlugin = 0;
OBSESerializationInterface * gSerialize;

TESObjectREFR* PlayerActorList[MAXCLIENTS];
//UserInterface usrInterface;

bool bFrameRendered = false;

extern bool FindEquipped(TESObjectREFR* thisObj, UInt32 slotIdx, FoundEquipped* foundEquippedFunctor, double* result);


extern "C" void OpenLog(int i)
{
	gLog.Open("OblivionOnline_bootstrap.log"); // Or else all our macros wouldn't work - discard
}
/* UDP is disabled - for now */
#ifdef DO_UDP
DWORD WINAPI UDPThread(LPVOID Params)
{
	char buf[PACKET_SIZE];
	int rc;
	int udpsock = socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in addr;
	struct sockaddr_in remoteaddr;
	InPacket * pkg;
	if(udpsock == -1)
	{
		gClient->GetIO()<< FatalError << "Couldn't create UDP socket "<<endl;
	}
	memset(&addr,0,sizeof(addr));
	addr.sin_port =htons();
	addr.sin_addr.s_addr = ADDR_ANY;
	rc = bind(udpsock,(sockaddr *)&addr,sizeof(addr)); //TODO: Error checking
	while(gClient->GetIsConnected())
	{
		int fromlen = sizeof remoteaddr;
		rc=recvfrom(udpsock,buf,PACKET_SIZE,0,(sockaddr *)&remoteaddr,&fromlen);
		pkg = new InPacket(gClient->GetEntities(),&gClient->GetIO(),(BYTE *) buf,rc);
		pkg->HandlePacket();
		delete pkg;
	}
} 
#endif
DWORD WINAPI RecvThread(LPVOID Params)
{
	char buf[PACKET_SIZE];
	int rc;
	InPacket * pkg;
	gClient->GetIO() << "Receive thread started" <<endl;
	while(gClient->GetIsConnected())
	{
		rc = recv(gClient->GetSocket(),buf,PACKET_SIZE,0); //TODO: Doesn't receive  UDP
		if(rc == SOCKET_ERROR)
		{
			SetConnectionMessage("Server dropped connection");
			gClient->GetIO() << "Server dropped connection" << endl;
			gClient->Disconnect();
		}
		pkg = new InPacket(gClient->GetEntities(),&gClient->GetIO(),(BYTE *)buf,rc);
		pkg->HandlePacket();
		delete pkg;
	}
	return 0;
}

extern "C" {
static void OO_LoadCallback(void * reserved)
{
	if(!gClient)
	{
		gClient = new GameClient();
	}
}
bool OBSEPlugin_Query(const OBSEInterface * obse, PluginInfo * info)
{
	//_MESSAGE("Starting plugin query ...");
	char ErrorBuf[2048]; // Necessary because we do not have an I/O system yet
	// fill out the info structure
	info->infoVersion = PluginInfo::kInfoVersion;
	info->name = "OblivionOnline";
	info->version = (SUPER_VERSION << 16) &&MAKEWORD(MAIN_VERSION,SUB_VERSION);
	// version checks
	if(!obse->isEditor)
	{
		if(obse->obseVersion < OBSE_VERSION_INTEGER)
		{
			sprintf(ErrorBuf,"OBSE version too old (got %08X expected at least %08X)", obse->obseVersion, OBSE_VERSION_INTEGER);
			MessageBoxA(NULL,ErrorBuf,"Error loading OblivionOnline",0);
			return false;
		}

		if(obse->oblivionVersion != OBLIVION_VERSION)
		{
			
			sprintf(ErrorBuf,"Incorrect Oblivion version (got %08X need %08X)", obse->oblivionVersion, OBLIVION_VERSION);
			MessageBoxA(NULL,ErrorBuf,"Error loading OblivionOnline",0);
			return false;
		}
	}
	else
	{
		// no version checks needed for editor
	}

	// version checks pass
	gSerialize = (OBSESerializationInterface *) obse->QueryInterface(kInterface_Serialization);
	return true;
}

bool OBSEPlugin_Load(const OBSEInterface * obse)
{
	//_MESSAGE("Loading OO Commands");
	gPlugin = obse->GetPluginHandle();
	obse->SetOpcodeBase(0x22D0); // Our codebase

	//Connection commands
	obse->RegisterCommand(&kMPConnectCommand);
	

	//Data sending
	obse->RegisterCommand(&kMPSendActorCommand);
	obse->RegisterCommand(&kMPSendChatCommand);


	//Data injecting
	obse->RegisterCommand(&kMPGetPosXCommand);
	obse->RegisterCommand(&kMPGetPosYCommand);
	obse->RegisterCommand(&kMPGetPosZCommand);
	obse->RegisterCommand(&kMPGetRotZCommand);
	obse->RegisterCommand(&kMPGetRotYCommand);
	obse->RegisterCommand(&kMPGetRotXCommand);
	obse->RegisterCommand(&kMPGetCellCommand);
	obse->RegisterCommand(&kMPGetIsInInteriorCommand);
	//Debug
	obse->RegisterCommand(&kMPGetDebugDataCommand);

	//Misc.
	obse->RegisterCommand(&kMPGetSpawnedRefCommand);
	obse->RegisterCommand(&kMPSpawnedCommand);
	obse->RegisterCommand(&kMPTotalPlayersCommand);
	obse->RegisterCommand(&kMPDisconnectCommand);
	obse->RegisterCommand(&kMPClearSpawnCommand);

	//Equipment
	obse->RegisterCommand(&kMPGetAddItemCommand);
	obse->RegisterCommand(&kMPGetRemoveItemCommand);
	obse->RegisterCommand(&kMPGetEquipItemCommand);
	obse->RegisterCommand(&kMPGetUnEquipItemCommand);


	obse->RegisterCommand(&kMPGetNewObjectCommand);
	obse->RegisterCommand(&kMPGetMyIDCommand);
	
	obse->RegisterCommand(&kMPShowGUICommand);
	obse->RegisterCommand(&kMPGetParentCellOrWSCommand);
	
	//_MESSAGE("Done loading OO Commands");
	if(!obse->isEditor)
	{
		gSerialize->SetLoadCallback(gPlugin,OO_LoadCallback);
	}
	return true;
}
};
