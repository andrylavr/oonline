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

#include "ModuleManager.h"
#include "CoreAdminModules.h"

#include "GameServer.h"
#include "Entity.h"
 const char *PlayerAdminModule::GetDisplayName()
{
	return "Players";
}
const char *PlayerAdminModule::GetName()
{
	return "players";
}
bool PlayerAdminModule::ShowInMenu()
{
	return true;
}
std::string * PlayerAdminModule::GetData(std::list<std::string> *parameters)
{
	std::string *retval = new std::string();
	//TODO: Add Private messaging and kicking players
	*retval = "<div align=\"center\"><strong>Players</strong><table><tr><td>ID</td><td>Name</td><td>IP</td><td></td><td></td></tr>";
	std::map<UINT32,Entity *>::const_iterator iter =  m_gs->GetEntities()->GetPlayerList().begin();
	std::map<UINT32,Entity *>::const_iterator end=  m_gs->GetEntities()->GetPlayerList().end();
	while(iter != end)
	{
		*retval += "<tr><td>";
		*retval += (*iter->second).RefID();
		*retval += "</td><td>";
		*retval += (*iter->second).Name();
		*retval += "</td><td>";
		*retval += "</td><td> <a href=\"players,kick,";
		*retval += (*iter->second).RefID();

		*retval += "\"></td><td>";
		*retval += " </td></tr>";
		iter++;
	}
	*retval += "</table>";
	return retval;
}