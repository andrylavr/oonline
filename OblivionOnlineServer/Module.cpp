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

#include "Module.h"
#ifndef WIN32
#include <dlfcn.h>
#endif
	//TODO: Add implementations
#include "GameServer.h"
#include "ModuleManager.h"
#include "ExternInterface.h"
#include "GameServer.h"
Module::Module(ModuleManager*mm, GameServer * gs,std::string Filename )
{
	InitialiseCallback callback;
	m_gs = gs;
	m_mm = mm;
#ifdef WIN32
	//load module
	//(sizeof(void *) == sizeof(HMODULE)); //static assert to verify the Win32 define of HMODULE
	Filename += ".dll";
	m_data = (void *)LoadLibraryA(Filename.c_str());
	if(!m_data)
	{
		m_gs->GetIO() << FatalError << "Cannot load .dll file"<< Filename <<endl;
		TerminateProcess(GetCurrentProcess(),1);
	}
	callback = (InitialiseCallback) GetProcAddress((HMODULE)m_data,"OnLoad");
	if(!callback)
	{
		if(!m_data)
		{
			m_gs->GetIO() << FatalError << "Cannot load function OnLoad from"<< Filename <<endl;
			TerminateProcess(GetCurrentProcess(),1);
		}
	}
#else
	//Clear error
	char * err= dlerror();
	Filename =string("./")+Filename;
	m_data = (void *)dlopen(Filename.c_str(),RTLD_NOW);
	err = dlerror();
	if(!m_data || err)
	{
		m_gs->GetIO() << FatalError << "Cannot load shared library "<<Filename <<"err: " << err <<  endl;
		exit(1);
	}
	callback = (InitialiseCallback) dlsym(m_data,"OnLoad");
	err = dlerror();
	if(!callback || err)
	{
		m_gs->GetIO() << FatalError << "Cannot load function OnLoad: error : "<< err <<endl;
		exit(1);
	}

//#error("Module loading not implemented");
#endif
	plugin = callback(gs,VERSION_SUPER,VERSION_MAJOR,VERSION_MINOR);
	m_gs->GetEventSys()->DefaultEvents.EventLoadModule(this); 
	m_gs->GetIO() << BootMessage << "Module " << plugin->Name << " Version " << plugin->Version << " (" <<plugin->VersionName << " ) by "
		<< plugin->Author << "successfully loaded from file " << Filename << endl;
	plugin->PrintWelcome();
}
Module::~Module(void)
{
	m_gs->GetEventSys()->DefaultEvents.EventUnloadModule(this);
	if(plugin->shutdown)
		plugin->shutdown();
#ifdef WIN32
	FreeLibrary((HMODULE)m_data);
#endif
}
