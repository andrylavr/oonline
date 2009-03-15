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
#ifndef OOEXTERNINTERFACE_H
#define OOEXTERNINTERFACE_H
#ifdef WIN32
#include <Windows.h>
#include <guiddef.h>
#else
#include <stdint.h>
#include <cstring>
typedef uint8_t BYTE;
struct GUID {
	uint32_t Data1;
	uint16_t Data2;
	uint16_t Data3;
	uint8_t  Data4[8];
	bool operator==(const GUID &other) const
	{
		return (other.Data1==Data1 && other.Data2==Data2 &&
			other.Data3==Data3 && !memcmp(other.Data4,Data4,8) );
	}
};
#endif
class GameServer;
class ModuleManager;
typedef void (*ShutdownCallback)(void);
class PluginInfo
{
public:
	char Name[128],VersionName[32],Author[64],Website[256],AuthorEmail[256];
	GUID versionid,modid; // Modid = same for all versions of a mod, VersionID: Specifies that one version
	unsigned int Version; // numerical version.
	ShutdownCallback shutdown;
	virtual void	PrintWelcome(){}; // used to print a welcome message: Totally useless, but if there is no virtual member
	// Visual C++ 9 doesn't make the virtual table ( which we need for DynamicCast) 
};
typedef PluginInfo *(*InitialiseCallback) (GameServer *gs,BYTE VersionSuper,BYTE VersionMajor,BYTE VersionMinor);
#define ModuleContext unsigned int

#ifdef _MSC_VER
#define OO_MODULE_EXPORT __declspec( dllexport )
#else
//POSIX needs no dllexport
#define OO_MODULE_EXPORT
#endif

#endif
