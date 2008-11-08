#pragma once
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
#include "GlobalDefines.h"
#include "ExternInterface.h"

#ifdef WIN32
#include <Windows.h>
#endif
class Module
{
public:
	Module(ModuleManager *mm,GameServer * gs,std::string Filename); // Module has to contain an exported procedure called "OnLoad"
	~Module(void);
	const GUID& GetGUID()
	{
		return plugin->modid;
	}
	const GUID& GetVersionID()
	{
		return plugin->versionid;
	}
	const int GetVersion()
	{
		return plugin->Version;
	}
	const char *Name()
	{
		return plugin->Name;
	}
	const char *Author()
	{
		return plugin->Author;
	}
	const char *Website()
	{
		return plugin->Website;
	}
	const char *AuthorEmail()
	{
		return plugin->AuthorEmail;
	}
	const char *VersionName()
	{
		return plugin->VersionName;
	}
	PluginInfo * GetPluginInfo()
	{
		return plugin;
	}
private:
	void *m_data; // implementation specific - WIN32:  Hmodule is a void* ...
	GameServer *m_gs;
	
	PluginInfo *plugin;
	ModuleManager *m_mm;
};
 
