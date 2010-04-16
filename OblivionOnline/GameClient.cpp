/*

Copyright(c) 2007-2010   Julian Bangert 

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
#include "GameClient.h"
#include "LogIOProvider.h"
#include "UserInterface.h"
#include "OutPacketStream.h"
#include "OBSEFunctions.h"
#include "ClientEntityUpdateManager.h"
#include "NetworkConnection.h"
#include "boost/foreach.hpp"
#define MOVE_THRESHOLD 0.2
bool g_bRenderGUI = true;
extern bool FindEquipped(TESObjectREFR* thisObj, UInt32 slotIdx, FoundEquipped* foundEquippedFunctor, double* result);
static void SendActorPosition(TESObjectREFR *act,ClientEntity *ent)
{	
	if(abs(act->posX - ent->PosX())> MOVE_THRESHOLD || abs(act->posY - ent->PosY()) > MOVE_THRESHOLD
		|| abs(act->posZ - ent->PosZ()) > MOVE_THRESHOLD || abs(act->rotZ - ent->RotZ()) > MOVE_THRESHOLD
		|| abs(act->rotX - ent->RotX())>MOVE_THRESHOLD ||abs(act->rotY - ent->RotY()) > MOVE_THRESHOLD)
	{
		if(act->parentCell->worldSpace == NULL)
			ent->SetCell(act->parentCell->refID,true);
		else
			ent->SetCell(act->parentCell->worldSpace->refID,false);
		ent->MoveNRot(act->posX,act->posY,act->posZ,act->rotX,act->rotY,act->rotZ);
	}
}
static void SendActorValueMod(Actor *act,ClientEntity *ent)
{
	for(BYTE i = 8;i <= 10;i++) // Only 8;9;10
	{
		ent->SetActorValueMod(i,(short)act->GetActorValue(i)- (short)act->GetBaseActorValue(i));
	}
}
static void SendActorValues(Actor *act,ClientEntity *ent)
{
	ent->SetActorValue(8,act->GetBaseActorValue(8));
	ent->SetActorValue(9,act->GetBaseActorValue(9));
	ent->SetActorValue(10,act->GetBaseActorValue(10));
}
static void SendActorEquip(Actor *act,ClientEntity *ent)
{
	feGetObject getObject;
	double itemResult;
	UInt32* itemRef = (UInt32*)&itemResult;
	for(BYTE i = 0; i <= 20; i++) // traverse Slots
	{
		if(i == 18 || i == 19 || i== 9 || i == 10 || i == 11 || i == 12 || i == 14) // These do not exist 
			continue;
		if (!FindEquipped(act, i, &getObject, &itemResult))
			ent->SetEquip(i,0);
		else
			ent->SetEquip(i,*itemRef);
	}
}
static void SendActorAnimation(Actor *act,ClientEntity *ent)
{
	ActorAnimData *animdata = GetActorAnimData(act);
	if(!animdata)
		return;
	for(int i = 0;i < 43;i++)
	{
		ent->SetAnimation(i,animdata->FindAnimInRange(i));
	}
}
GameClient::GameClient(void) : UpdateQueue()
{
	/*
	1 IO
	2 Network
	3 ClientEntity
		*/
	IOSystem::Instance().RegisterIOProvider(new LogIOProvider(&IOSystem::Instance(),LogLevel::BootMessage,"OblivionOnline.log"));
	IOStream::Instance() << BootMessage << "Initializing game client: IO running" <<endl;
	Entities = new ClientEntityManager(&IOStream::Instance());
	Entities->SetUpdateManager(new ClientEntityUpdateManager(Entities));
	bIsConnected = false;
	bIsMasterClient = false;
	bIsInitialized = false;
}

GameClient::~GameClient(void)
{
	delete Entities;
}

int GameClient::Initialize()
{
	long rc;
	WSADATA wsa;
	rc = WSAStartup(MAKEWORD(2,0),&wsa);
	ServerSocket = socket(AF_INET,SOCK_STREAM,0);
	IOStream::Instance() << BootMessage<< "OblivionOnline connecting" <<endl;
	IOStream::Instance() <<BootMessage<<"Initializing GUI" <<endl;
	//InitialiseUI();
	bIsInitialized = false;
	//Entities->DeleteEntities();
	TotalPlayers = 0;
	LocalPlayer = MAXCLIENTS;
	return rc;
}

int GameClient::Deinitialize()
{
	bIsInitialized = false;
	TotalPlayers = 0;
	GetEntities()->DeleteEntities();
	closesocket(ServerSocket);
	ServerSocket = INVALID_SOCKET;
	WSACleanup();
	DeinitialiseUI();
	//D3DHookDeInit();

	return 1;
}

bool GameClient::Connect()
{

	char IP[15] = "";
	SOCKADDR_IN ServerAddr;
	unsigned short ClientPort = 41805;
	long rc = 0;
	if(!bIsConnected)
	{
		IOStream::Instance() << BootMessage << "Initializing Connection" <<endl; 
		Initialize();

		FILE *Realmlist = fopen("realmlist.wth","r");
		if(!Realmlist)
		{
			IOStream::Instance() << Error << "File realmlist.wth could not be found" << endl;
			return false;
		}
		while(!feof(Realmlist))
		{
			fscanf(Realmlist,"%14s",IP);
			if(!fscanf(Realmlist,"%hu",&ClientPort))
				ClientPort = 41805;
			IOStream::Instance() << BootMessage << "Trying to connect to "<<IP << " : "<<ClientPort <<endl;
			memset(&ServerAddr,NULL,sizeof(SOCKADDR_IN));
			ServerAddr.sin_addr.s_addr = inet_addr(IP);
			ServerAddr.sin_port = htons(ClientPort);
			ServerAddr.sin_family = AF_INET;
			rc = connect(ServerSocket,(SOCKADDR *)&ServerAddr,sizeof(SOCKADDR));
			if(rc == SOCKET_ERROR)
			{
				IOStream::Instance() << "Error" << WSAGetLastError() << " establishing connection " <<endl;
				continue;
			}
			else 
			{
				ChunkPermissions all(MATCH_ALL);
				IOStream::Instance() << "Successfully connected" << endl;
				conn = new NetworkConnection(GetEntities(),ServerSocket,boost::bind<>(&GameClient::Disconnect,boost::ref(*this)) );		
				conn->SetPermissions(all);
				IOStream::Instance() << BootMessage << "Waiting for Player ID" <<endl;
				bIsConnected = true;
				break;
			}
		}
		fclose(Realmlist);
	}
	return true;
}

void GameClient::Disconnect()
{
	if(bIsConnected)
	{
		Deinitialize();
		bIsConnected = false;
		IOStream::Instance() << BootMessage << "Successfully disconnect" << endl;
	}else{
		IOStream::Instance() << BootMessage << " You are not connected" << endl;
	}
}
bool GameClient::RunFrame()
{
	ClientEntity * ent;  
	Actor  * actor = NULL;
	BYTE Status;
	if(!gClient->GetIsConnected())
		return false;
	//Check if Menu Mode:

	InterfaceManager* intfc = InterfaceManager::GetSingleton();
	if(!intfc->IsGameMode())
		g_bRenderGUI = false;
	else
		g_bRenderGUI = true;

	if(!gClient->GetIsInitialized() )
	{
		gClient->GetConnection().Process();//Poll connection until a player id is received
		return true;
	}
	// A heavy command xD
	// 1 - send local player data up .
	// 2 - send health magicka and fatigue  + equip up.
	// if MC :
	// 2 - send up position , stat equip , etc of NPCs
	//(*g_thePlayer) is ignored
	ent = (ClientEntity *)gClient->GetEntities()->GetOrCreateEntity(gClient->GetLocalPlayer());
	//gClient->GetServerStream()->Send(); // Prevent Lag
	SendActorPosition(*g_thePlayer,ent);
	SendActorValues(*g_thePlayer,ent);
	SendActorEquip(*g_thePlayer,ent);
	SendActorAnimation(*g_thePlayer,ent);
		//Find all cells any "ignored objects" are in. these are mostly players.
		std::set<TESObjectCELL *> cells;
		cells.insert((*g_thePlayer)->parentCell);
		BOOST_FOREACH(UINT32 i,ignore)
		{
			TESObjectREFR *form = (TESObjectREFR *)LookupFormByID(i);
			if(!form)
				continue;
			if(!form->parentCell) continue;

			if(cells.find(form->parentCell)  == cells.end())//Not present
				cells.insert(form->parentCell);
		}
		//now we process each cell...
		BOOST_FOREACH(TESObjectCELL *Cell,cells)
		{
			TESObjectCELL::ObjectListEntry * ListIterator = &Cell->objectList;		

			while(ListIterator) // Iterate the entities
			{
				if(IsRefIDIgnore(ListIterator->refr->refID)) // Do not synchronize objects used by OblivionOnline
				{
					ent = (ClientEntity *) gClient->GetEntities()->GetOrCreateEntity(ListIterator->refr->refID);
					if(GetIsMasterClient())
						SendActorPosition(ListIterator->refr,ent);					
					if(ListIterator->Info()->IsActor())
					{
						Actor * actor = (Actor *)LookupFormByID(ListIterator->refr->refID);
						{
							if(GetIsMasterClient())
							{
								SendActorValues(actor,ent);
								SendActorEquip(actor,ent);
								SendActorAnimation(actor,ent);		
							}
							SendActorValueMod(actor,ent);
						}				
					}
				}
				ListIterator = ListIterator->next;
			}
		}
	gClient->GetConnection().Process();
	return true;
}

bool GameClient::EmptyPlayerCell()
{
	const UINT32 storagecell = 98410; // marked "Testdungeon"
	TESObjectCELL::ObjectListEntry * iter = &(*g_thePlayer)->parentCell->objectList; //TODO: WIPE worldspace!
	while(iter)
	{
		if(iter->Info()->refID == (*g_thePlayer)->refID) { iter= iter->next;  continue;}
		Entity * ent = gClient->GetEntities()->GetOrCreateEntity(iter->Info()->refID);
		assert(ent);
		ent->SetCell(storagecell,0,true); // Fake a network wipe!
		iter = iter->next;
	}
	return true;
}

void GameClient::IgnoreRefID(UINT32 val) /* to register OO pure ref IDs */
{
	if(ignore.find(val) == ignore.end())
		ignore.insert(val);
}

bool GameClient::IsRefIDIgnore(UINT32 val)
{
	return ignore.find(val) == ignore.end();
}

void GameClient::SetPlayerID( UINT32 Value )
{
	LocalPlayer = Value;
	bIsInitialized = true;
	Console_Print("Received Player ID %u",Value);
}