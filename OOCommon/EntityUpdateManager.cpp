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
#include "EntityManager.h"
#include "Entity.h"
#include <unordered_map>
const std::list<Entity *>* EntityUpdateManager::GetPlayersInCell( UINT32 CellID ) /* Refactor this */
{
	std::tr1::unordered_map<UINT32,std::list<Entity *>>::iterator iter= m_entities_in_cells.find(CellID);
	if(m_entities_in_cells.end() == iter)
		return NULL;
	else
		return &(iter->second);
}
OO_API  void EntityUpdateManager::OnCellChange( Entity *ent,UINT32 oldCell, bool Inbound )
{
	std::tr1::unordered_map<UINT32,std::list<Entity *>>::iterator iter;
	if(oldCell) // oldCell==0 is special
	{
		iter= m_entities_in_cells.find(oldCell);
		if(m_entities_in_cells.end() == iter) // The entity should be registered in a cell
		{
			throw "This should never happen.. Entity was not registered in list, but has an oldCell value passed" ;
		}
		else
		{
			std::list<Entity *> & list = iter->second;
			for(std::list<Entity *>::iterator i=list.begin();list.end()!=i;i++)
			{
				if(ent == *i)
				{
					list.erase(i);
					if(list.empty())
						m_entities_in_cells.erase(iter);
					break;
				}
			}
		}
	}
	iter=m_entities_in_cells.find(ent->CellID());
	if(iter == m_entities_in_cells.end())
	{
		std::list<Entity *> list;
		iter = m_entities_in_cells.insert(std::pair<UINT32,std::list<Entity *> >(ent->CellID(),list) ).first;
	}
	iter->second.push_back(ent);
}