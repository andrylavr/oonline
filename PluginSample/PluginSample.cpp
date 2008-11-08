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
#include <iostream>
#include "PluginSample.h"
#include "EntityManager.h"
#include "EventSystem.h"
#include "gameserver.h"
//Attention: You should AVOID global variables like this, you will understand why i had to use one here
// ( InteropSample) later.
// That is because Gameservers can FORK,meaning multiple instances in one process. 
// At the moment however, this is not implemented,so if you absolutely find no way around it, 
// write NON-FORKABLE in your release notes and version name, so people see it

GameServer * g_gs; 

static const GUID modid =  //Change this if you make a new mod
	{ 0x35527435, 0xcb8, 0x4a74, { 0xbb, 0x71, 0x5, 0xaf, 0x2a, 0x87, 0xc0, 0x27 } };
// {2185F53A-F4BA-437c-B424-C78FC0B23A37}
static const GUID versionid =  // change this every public release
{ 0x2185f53a, 0xf4ba, 0x437c, { 0xb4, 0x24, 0xc7, 0x8f, 0xc0, 0xb2, 0x3a, 0x37 } };

void OnServerBoot()
{
	g_gs->GetIO() << GameMessage << "Module is really ready----"<< std::endl;
}
void OnShutdown()
{
	g_gs = 0;
}
//this function is the mmain function of our plugin. it can hook up calls and events
extern "C" OO_MODULE_EXPORT PluginInfo * OnLoad(GameServer *gs,BYTE versionsuper,BYTE versionmajor ,BYTE versionminor)
{
	//These comments in here should give a VERY quick overview over our extendibility system
	//If you find any bugs in the interface, please file a bug AND make a forum post
	//Do NOT rely on these bugs , because they will be fixed
	PluginSampleInfo *retval = new PluginSampleInfo();
	// {4A3B211B-AAA4-4b2e-AFDD-A91CAA5F79D0}
	// {35527435-0CB8-4a74-BB71-05AF2A87C027}
	
	//First, we fill out the important Plugin Info structure
	retval->modid = modid;
	retval->versionid = versionid;
	strcpy(retval->Name, "OblivionOnline Test mod"); // most compilers cann0ot assign a static char to another...
	strcpy(retval->VersionName,"useless release");
	strcpy(retval->Author,"Masterfreek64 doesn't want to admit it");
	retval->Version = 1;
	retval->shutdown = OnShutdown;
	g_gs = gs;
	
	//Here we doi some useless output
	//printf("we are in business\n"); //DO NOT DO THIS. EVER.  use the IO system. It took me 2 weeks to do the IO system
	// and it makes life REALLY easy
	/* It works as follows:
	There is a number of "providers" which are various places the IO system can put the output it gets, such as the console,
	the admin chat line, the log file, etc *
	Then there are various message levels:
	BootMessage ,
	SystemMessage,
	GameMessage,
	Warning,
	Error,
	FatalError,
	PlayerChat,
	AdminChat
	You can make output by (a) Get the Output stream ( gs->GetIO() here ) (b) Set the message level ( stream it into it) 
	by doing something like << BootMessage (c) Stream in the text (D) END WITH AN ENDL.
	The last one is important or it'll mess up the entire IO system */
	gs->GetIO()<< BootMessage << "and we can also use the real IO system" << std::endl;

	//Now comes the SINGLE MOST IMPORTANT concept of ALL. 


	// Events:
	// An event is a SIGNAL. It is like a list of callbacks.
	// An event is implemented using a BOOST::SIGNAL. Everything can provide events, and your callbacks should have the format specified in the boost signal
	// You can define a signal by 
	// boost::signal < void() > event // Replace void() by the function type of the callback
	// More in BOOST::SIGNAL documentation.
	// I originally had complemented my  own implementation of a callback system , but Boost:Signal proved to be faster
	// more efficient and easier to implement.
	// You can subscribe to an event by Event.connect()
	// and trigger one with Event()
	// Global Events are stored in this DefaultEvents structure. They are per-server instance.
	gs->GetEventSys()->DefaultEvents.EventBoot.connect(OnServerBoot);
	//Events like LifeChange are also triggered globally, if you want to register EVERY hit
	// you can also register an event ON AN ENTITY:(like death, chat,etc)

	// Now you might go over and actually READ the InteropSample.cpp
	return retval;
}

