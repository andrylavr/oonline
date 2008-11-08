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
#include "Pluginsample.h"

#include "EntityManager.h"
#include "ModuleManager.h"
#include "EventSystem.h"
#include "gameserver.h"
//This function gets called by the plugin.
//You can think of this as a second plugin
// its purpose is to show how you can communicate with various plugins present

static const GUID ownid =  //Change this if you make a new mod
	{ 0x35527435, 0xcb8, 0x4a74, { 0xbb, 0x71, 0x5, 0xaf, 0x2a, 0x87, 0xc0, 0x27 } };
void RandomCallback()
{
	g_gs->GetIO() << GameMessage << "This is SO random" << std::endl;
}
void LoadInteropSample()
{
	//We assume that we have g_gs ( the other plugin filled it ;) )
	// if that really were a seperate plugin you would have to initialize it obviously

	//First we find the module we want to interact with. 
	//you should use the GUID to resolve ambiguities.
	//here, only for demonstration, we interact with ourselves and use our own GUID from the const
	Module *othermod =  g_gs->GetModules()->FindModule(ownid);
	if(!othermod)
	{
		g_gs->GetIO() << Error << " Other Module we want to interact with not found. Features disabled" << endl;
		// Maybe you only need the mod for optional purposes?
		return;
	}

	// Insert the required version here. Maybe also check for version GUIDs, etc
	// you can also warn the user if that version was not tested against or has known problems
	if(othermod->GetVersion() < 1) 
	{
		g_gs->GetIO() << Error << " The other module is not new enough" ;
	}
	// The module you want to interact with should have Events. These should be "published" by overloading Plugininfo.
	// Therefore we have to dynamic-cast the pointer we get to a derived pointer
	PluginSampleInfo * info = dynamic_cast<PluginSampleInfo *> (othermod->GetPluginInfo());
	if(!info)
	{
		// It did not cast.
		// either the interface was changed, the module not compiled correctly or the GUID used for another mod, (etc, etc , etc...)
		// You should warn the user
		g_gs->GetIO() << FatalError << " We couldn't dynamic_cast  the Plugin Handle. Exiting" << endl;
		return;
	}
	// We have all the data from the overloaded data now
	//We can raise the event now
	info->RandomCallbackEvent();
	// And we can subscribe to it( the previous raising will be ignored)
	info->RandomCallbackEvent.connect(RandomCallback);
	// Now we wait for the othe rplugin to raise this event.
	
}