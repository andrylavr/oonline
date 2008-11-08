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
//#include <string>
//#include <list>
#include "ModuleManager.h"
#include "Module.h"
#include "CoreAdminModules.h"

#include "GameServer.h"
class Module;
 const char *ModuleAdminModule::GetDisplayName()
{
	return "Loaded Modules";
}
const char *ModuleAdminModule::GetName()
{
	return "modules";
}
bool ModuleAdminModule::ShowInMenu()
{
	return true;
}
std::string * ModuleAdminModule::GetData(std::list<std::string> *parameters)
{
	std::string *retval = new std::string();
	*retval = "<div align=\"center\"><strong>Modules Loaded</strong><table><tr><td>Name</td><td>Author</td><td>Version Name</td><td>Numeric Version</td></tr>";
	std::list<Module *>::iterator iter = m_gs->GetModules()->BeginIter();
	std::list<Module *>::iterator end = m_gs->GetModules()->EndIter();
	while(iter != end)
	{
		*retval += "<tr><td> <a href=\"";
		*retval += (*iter)->Website();
		*retval += "\">";
		*retval += (*iter)->Name();
		*retval += "</a></td><td><a href \"mailto:";
		*retval +=  (*iter)->AuthorEmail();
		*retval += "\">";
		*retval += (*iter)->Author();
		*retval += "</a></td><td>";
		*retval += (*iter)->VersionName();
		*retval += "</td><td>";
		*retval +=  (int)(*iter)->GetVersion();
		*retval += " </td></tr>";
		iter++;
	}
	*retval += "</table>";
	return retval;
}