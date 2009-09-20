/*

Copyright(c) 2007-2009   Julian Bangert aka masterfreek64, Joseph Pearson aka chessmaster42 

This file is part of OblivionOnline.

    OblivionOnline is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    OblivionOnline is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Linking OblivionOnline statically or dynamically with other modules is making a combined work based
	on OblivionOnline. Thus, the terms and conditions of the GNU General Public License cover 
	the whole combination.

    In addition, as a special exception, the copyright holders of  OblivionOnline give you permission to 
	combine OblivionOnline program with free software programs or libraries that are released under
	the GNU LGPL and with code included in the standard release of Oblivion Script Extender by Ian Patterson (OBSE)
	under the OBSE license (or modified versions of such code, with unchanged license). You may copy and distribute such a system 
	following the terms of the GNU GPL for  OblivionOnline and the licenses of the other code concerned,
	provided that you include the source code of that other code when and as the GNU GPL
	requires distribution of source code.

	Note that people who make modified versions of  OblivionOnline are not obligated to grant this special exception
	for their modified versions; it is their choice whether to do so. 
	The GNU General Public License gives permission to release a modified version without this
	exception; this exception also makes it possible to release a modified version which carries 
	forward this exception.
*/
#pragma once
#ifndef CLIENTENTITY_H
#define CLIENTENTITY_H
#include <set>
#include <queue>
#include "../OOCommon/Entity.h"
class ClientEntity : public Entity
{
private:
public:
	ClientEntity(EntityManager *mgr,UINT32 refID,BYTE Status, bool TriggerEvents = false,bool GlobalSynch= false,
		float posX = 0 , float posY = 0 , float posZ = 0,UINT32 CellID = 0,bool IsInInterior = false,
		float rotX = 0 , float rotY = 0 , float rotZ = 0,short health = 0,short magicka = 0 , short fatigue = 0 ,
		bool female = false,UINT32 race = 0,std::string name = std::string("Unnamed"),std::string classname = std::string("")) :
	Entity(mgr,refID,Status,TriggerEvents,GlobalSynch,posX,posY,posZ,CellID,IsInInterior,rotX,rotY,rotZ,health,magicka,fatigue,female,race,name,classname)
	{
		
	}
	UINT32 GetNextEquipItem()
	{
		UINT32 retval;
		lock.lock();
		if(!EquipQueue.empty())
		{
			retval = EquipQueue.front();
			EquipQueue.pop();
		}
		else	
			retval = 0;
		lock.unlock();

		return retval;
	}
	UINT32 GetNextUnequipItem()
	{
		UINT32 retval;
		lock.lock();
		if(!UnEquipQueue.empty())
		{
			retval = UnEquipQueue.front();
			UnEquipQueue.pop();
		}
		else
			retval = 0;
		lock.unlock();
		return retval;
	}
	UINT32 GetNextAddItem()
	{
		UINT32 retval;
		lock.lock();
		if(!AddItemQueue.empty())
		{
			retval = AddItemQueue.front();
			AddItemQueue.pop();
		}
		else
			retval = 0;
		lock.unlock();
		return retval;
	}
	UINT32 GetNextRemoveItem()
	{
		UINT32 retval;
		lock.lock();
		if(!RemoveItemQueue.empty())
		{
			retval = RemoveItemQueue.front();
			RemoveItemQueue.pop();
		}
		else 
			retval = 0;
		lock.unlock();
		return retval;
	}
	void AddEquipItem(UINT32 fo)
	{
		lock.lock();
		AddItemQueue.push(fo);
		lock.unlock();
	}
	void AddRemoveItem(UINT32 fo)
	{
		lock.lock();
		RemoveItemQueue.push(fo);
		lock.unlock();
	}
	void AddAddItem(UINT32 fo)
	{
		lock.lock();
		AddItemQueue.push(fo);
		lock.unlock();
	}
	void AddUnequipItem(UINT32 fo)
	{
		lock.lock();
		UnEquipQueue.push(fo);
		lock.unlock();
	}
};

#endif
