/*
This file is part of OblivionOnline Server- An open source game server for the OblivionOnline mod
Copyright (C)  2008   Julian Bangert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.


You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "GameServer.h"
#include "LuaSystem.h"
#include "ScreenIOProvider.h"
#include "LogIOProvider.h"
#include "NetworkSystem.h"
#include "ChatIOProvider.h"
#include "EventSystem.h"
#include "ModuleManager.h"
#include "RemoteAdminServer.h"
#include "PlayerManager.h"
#include "ServerEntityUpdateManager.h"
#include <string>
#include <sstream>
#include "curl/curl.h"
GameServer::GameServer(void)
{
	//Initialize all subsystems
	/*
	1. IO System -- logging obviously comes first
	2. Lua system - Configurations  Done - add operator[] perhaps
	3. Event - it triggers everything - IO doesn't need event anymore
	4 .ScreenIOProvider Done
	5 .LogIOProvider Done	
	6. Netsystem  Done TCP(DONE) UDP(DONE)
	7. Entity Manager
	8. ChatIOProvider Done
	9. PartyLine ---
	10. Module Manager
	11. LUA OnLoad call
	


	Perhaps some other stuff
	Finish of with a onload event
	*/
	IOStream::Instance().RegisterIOProvider(new ScreenIOProvider(&IOSystem::Instance(),BootMessage));//TODO : Fix that
	try{
		DisplayBootupMessage();
		m_script = new LuaSystem(this);

		m_script->RunStartupScripts("ServerLaunch.lua");
		m_Evt = new EventSystem(this);
		IOStream::Instance() <<BootMessage<<"Opening Log file" << endl;
		IOStream::Instance().RegisterIOProvider(new LogIOProvider(&IOSystem::Instance(),BootMessage,m_script->GetString("Logfile")));	
		IOStream::Instance() <<BootMessage<<"Script , Event and Local IO running" << endl;
		m_Netsystem = new NetworkSystem(this);
		m_Entities = new EntityManager(&IOStream::Instance() );
		m_Players = new PlayerManager(m_Entities,m_Netsystem);
		m_Entities->SetUpdateManager(new ServerEntityUpdateManager(m_Players,m_Entities,m_Netsystem));
		IOStream::Instance().RegisterIOProvider(new ChatIOProvider(this,&IOSystem::Instance()));
		m_Modules = new ModuleManager(this);
		m_Admin = new RemoteAdminServer(this);
		m_script->RunScriptLine("OnLoad()");
		m_Evt->DefaultEvents.EventBoot();
		m_Netsystem->Start();
	}
	catch(std::exception e)
	{
		IOStream::Instance() << FatalError << "Error during initialization:"<<e.what()<<"--Quitting!"<<endl;
		exit(-1);
	}
	catch(...)
	{
		IOStream::Instance() << FatalError << "Unknown error occured during initialization. Quitting "<<endl;
		volatile int x=1;
		x--;
		sprintf(NULL,"%u",1/x); // THIS WILL DUMP CORE!
	}
	//m_script->PrintStatistics();
	//AdvertiseGameServer();
	
}

GameServer::~GameServer(void)
{
	/*
	inverse order from construction
	*/
	delete m_Modules;
	delete m_Netsystem;
	delete m_Entities;
	delete m_Evt;
	delete m_script;
}
// Creates ticks and runs the lua GC
void GameServer::RunServer()
{
	UINT64 tickcount = 0;
	clock_t tick_current,tick_next,tick_delta,tick_garbagecollect = 0;
	m_tickrate = m_script->GetInteger("TickRate");
	while(1)
	{
		tick_next = clock() + CLOCKS_PER_SEC  / m_tickrate;
		m_Evt->DefaultEvents.EventTick(tickcount++);
		tick_delta = tick_next - clock();
#ifdef WIN32
		Sleep( tick_delta * (CLOCKS_PER_SEC / 1000));
#else
		usleep(1000000/m_tickrate); // dirty, but apparently more precise
#endif
		tick_garbagecollect -= tick_delta;
		if(tick_garbagecollect <= 0)
		{
			tick_garbagecollect = CLOCKS_PER_SEC * 120;
			m_script->PrintStatistics();
		}
		
	}
}

void GameServer::DisplayBootupMessage()
{
	IOStream::Instance()  <<BootMessage<< "\nOblivionOnline Server version "<<VERSION_STREAM << "\n (c) 2008 by Julian Bangert \n\n" <<
		"This program is free software: you can redistribute it and/or modify\n" <<
		"it under the terms of the GNU AFFERO GENERAL PUBLIC LICENSE as published by the \n" <<
		"Free Software Foundation, either version 3 of the License, or (at your option) \n" <<
		"any later version.\n" <<

		"This program is distributed in the hope that it will be useful,\n" <<
		"but WITHOUT ANY WARRANTY; without even the implied warranty of\n" <<
		"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n" <<
		"GNU AFFERO GENERAL PUBLIC LICENSE for more details.\n" <<
		"You should have received a copy of the GNU AFFERO GENERAL PUBLIC LICENSE\n" <<
		"along with this program.  If not, see <http://www.gnu.org/licenses/>.\n" << endl;
	IOStream::Instance() <<BootMessage<<"Please note that you have to offer the source codes to this server software on the web for the users to download" << endl<<
		"For the official releases this is taken care of at http://googlecode.com/p/oonline/ , however if you modify ANYTHING you have to make the COMPLETE sources(also client, as that client is a derived work of the server) available to the users"<<endl;
}
