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
#pragma once
#include <string>
extern "C"
{
	#include "lua/lua.h"
	#include "lua/lualib.h"
	#include"lua/lauxlib.h"
}
#include "GameServer.h"
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#define STARTUP_SCRIPT "ServerLaunch.lua"
OO_API class LuaSystem
{
public:
	LuaSystem(GameServer *GS);
	~LuaSystem(void);
	OO_API bool RunStartupScripts(std::string Name);
	OO_API bool RunScriptLine(std::string Line);
	OO_API lua_Number GetNumeric(std::string Name);
	OO_API lua_Integer GetInteger(std::string Name);
	OO_API std::string GetString(std::string Name);
	OO_API lua_CFunction GetFunction(std::string Name);
	OO_API void SetFunction(std::string Name,lua_CFunction value);
	OO_API void SetNumeric(std::string Name,lua_Number value);
	OO_API void SetInteger(std::string Name,lua_Integer value);	
	OO_API void SetString(std::string Name,std::string Value);
	OO_API void PrintStatistics();
private:
	void DefaultSettings();
	lua_State *m_Lua;
	GameServer *m_GS;
	boost::mutex lock;
};
