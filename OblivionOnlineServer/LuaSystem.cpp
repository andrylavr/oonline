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
#include <boost/filesystem.hpp>
#include "LuaSystem.h"
#include "DefaultSettings.h"
#include "ModuleManager.h"
#include "PlayerManager.h"
int oolua_LoadModule(lua_State *state)
{
	const char *buf;
	GameServer *serv;
	buf =  lua_tostring(state,lua_gettop(state));
	if(!buf)
		return -1;
	lua_getglobal(state,"_OOCONTEXT");
	if(!lua_isuserdata(state,lua_gettop(state)))
		return 0;
	serv = (GameServer *)lua_touserdata(state,lua_gettop(state));
	if(serv)
	{
		serv->GetModules()->LoadModule(buf);
		return 0;
	}
	else
		return -2;
}
int oolua_AddPlayerID(lua_State *state)
{
	const char *buf;
	GameServer *serv;
	unsigned int PlayerID;
	buf =  lua_tostring(state,lua_gettop(state));
	if(!buf)
		return -1;
	PlayerID = atol(buf);
	if(PlayerID == 0)
		return -2;
	lua_getglobal(state,"_OOCONTEXT");
	if(!lua_isuserdata(state,lua_gettop(state)))
	return 0;
	serv = (GameServer *)lua_touserdata(state,lua_gettop(state));
	if(serv)
	{
		serv->GetPlayerManager()->AssignPlayerID(PlayerID);
		return 0;
	}
	else
	return -2;
}
LuaSystem::LuaSystem(GameServer *gs) : lock()
{
	m_GS = gs;
	m_Lua = lua_open();
	luaopen_base(m_Lua);
}

LuaSystem::~LuaSystem(void)
{
	lua_close(m_Lua);
}
bool LuaSystem::RunStartupScripts(std::string Name)
{
	IOStream::Instance() << BootMessage << "Working directory for startup scripts:" << boost::filesystem::current_path().string() << endl;
	DefaultSettings();
	if(luaL_dofile(m_Lua,Name.c_str()))
	{
		IOStream::Instance() << FatalError << "LUA ERROR:"<< lua_tostring(m_Lua, -1)<<endl;
		throw std::runtime_error("Couldn't run startup script!");
	}
}
bool LuaSystem::RunScriptLine(std::string Line)
{
	return luaL_dostring(m_Lua,Line.c_str());
}
lua_Number LuaSystem::GetNumeric(std::string Name)
{
	lock.lock();
	lua_getglobal(m_Lua,Name.c_str());
	if(!lua_gettop(m_Lua))
	{
		m_GS->GetIO() << Warning << "LUA:Invalid Number variable  " << Name << " accessed. Returning default 0"<<endl;
		lua_pushnumber(m_Lua,0);
	}
	lock.unlock();
	return lua_tonumber(m_Lua,lua_gettop(m_Lua));
}
lua_Integer LuaSystem::GetInteger(std::string Name)
{
	lock.lock();
	lua_getglobal(m_Lua,Name.c_str());
	if(!lua_gettop(m_Lua))
	{
		m_GS->GetIO() << Warning << "LUA:Invalid Integer variable  " << Name << " accessed. Returning default 0"<<endl;
		lua_pushinteger(m_Lua,0);
	}
	lock.unlock();
	return lua_tointeger(m_Lua,lua_gettop(m_Lua));
}
lua_CFunction LuaSystem::GetFunction(std::string Name)
{
	lock.lock();
	lua_getglobal(m_Lua,Name.c_str());
	if(!lua_gettop(m_Lua))
	{
		m_GS->GetIO() << Warning << "LUA:Invalid Function variable  " << Name << " accessed. Returning default &(abort)."
			<< "This will most likely crash the server AND all other multiplexed instances; and that is the best way!"<<endl;
		//TODO: this allows a single multiple server instance to crash all multiple instances... properly handle the exception
		//TODO: implement lua_functions/panic which will safely abort the program without abusing the stack frame
		lua_pushcfunction(m_Lua,(lua_CFunction)&abort);
	}
	lock.unlock();
	return lua_tocfunction(m_Lua,lua_gettop(m_Lua));
}
std::string LuaSystem::GetString(std::string Name)
{
	//TODO: Locking here. 
	const char *string = 0;
	lock.lock();
	lua_getglobal(m_Lua,Name.c_str());
	if(!lua_gettop(m_Lua))
	{
		m_GS->GetIO() << Warning << "LUA:Invalid string variable  " << Name << " accessed. Returning default empty string."<<endl;
		lua_pushstring(m_Lua,"");
	}
	if(lua_isstring(m_Lua,lua_gettop(m_Lua)))
		string = lua_tostring(m_Lua,lua_gettop(m_Lua));
	lock.unlock();
	if(string)
		return std::string(string);
	else
		return std::string("");
}
void LuaSystem::SetNumeric(std::string Name, lua_Number value)
{
	lock.lock();
	lua_pushnumber(m_Lua,value);
	lua_setglobal(m_Lua,Name.c_str());
	lock.unlock();
}
void LuaSystem::SetInteger(std::string Name, lua_Integer value)
{
	lock.lock();
	lua_pushinteger(m_Lua,value);
	lua_setglobal(m_Lua,Name.c_str());
	lock.unlock();
}
void LuaSystem::SetString(std::string Name, std::string value)
{
	lock.lock();
	lua_pushstring(m_Lua,value.c_str());
	lua_setglobal(m_Lua,Name.c_str());
	lock.unlock();
}
void LuaSystem::SetFunction(std::string Name,lua_CFunction value)
{
	lock.lock();
	lua_pushcfunction(m_Lua,value);
	lua_setglobal(m_Lua,Name.c_str());
	lock.unlock();
}
void LuaSystem::DefaultSettings()
{
	luaL_openlibs(m_Lua); //TODO: check if this is "safe"
	SetInteger("ServicePort",DEFAULT_GAMEPORT);
	SetInteger("AdminPort",DEFAULT_ADMINPORT);
	SetInteger("TickRate",DEFAULT_TICKRATE);
	SetString("Name",DEFAULT_SERVERNAME);
	SetString("RealmlistURI",DEFAULT_REALMLIST);
	SetString("Logfile",DEFAULT_LOGFILE);
	lua_register(m_Lua,"AddPlayerID",oolua_AddPlayerID);
	lua_pushcfunction(m_Lua,oolua_LoadModule);
	lua_setglobal(m_Lua,"LoadModule");
	lua_pushlightuserdata(m_Lua,m_GS);
	lua_setglobal(m_Lua,"_OOCONTEXT"); //TODO: Security vulnerability: Scripts can change an arbitrary pointer to a GS instance- A script could load a binary dump of a working GS instance AND make his own, but its not that important.
}

void LuaSystem::PrintStatistics()
{
	lock.lock();
	lua_gc(m_Lua,LUA_GCCOLLECT,0);
	m_GS->GetIO()<<SystemMessage<<"Lua Statistics: Total Script Memory used after Garbage Collection in Bytes:"<< lua_gc(m_Lua,LUA_GCCOUNT,0) * 1024 + lua_gc(m_Lua,LUA_GCCOUNTB,0) << std::endl;
	lock.unlock();
}