/*
This file is part of OblivionOnline Server- An open source game server for the OblivionOnline mod
Copyright (C)  2008-2010   Julian Bangert

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
#include "PlayerManager.h"
#include "NetworkSystem.h"
#include "Packets.h"
PlayerManager::PlayerManager(EntityManager *manager,NetworkSystem *Network):_lock(),_mgr(manager),m_MasterClient(0),_net(Network)
{
}

PlayerManager::~PlayerManager(void)
{
}

Player * PlayerManager::GetPlayer( SOCKET connection )
{
	boost::lock_guard<boost::mutex> guard(_lock);
	if(_playerIDs.empty())
	{
		throw std::runtime_error("No more Player IDs.");
	}
	Player *retval = new Player(this,_playerIDs.top(),connection,boost::bind(&NetworkSystem::OnDisconnect,boost::ref(*_net),_1));
	_playerIDs.pop();
	insert(retval);
	raw::PlayerID::Send(*retval,retval,retval->RefID());
	if(!m_MasterClient)
	{
		raw::ClientType::Send(*retval,retval->RefID(),1);
		m_MasterClient = retval->RefID();
	}
	else
		raw::ClientType::Send(*retval,retval->RefID(),0);
	return retval;
}

void PlayerManager::RemovePlayer( Player *Player )
{
	boost::lock_guard<boost::mutex> guard(_lock);
	_playerIDs.push(Player->RefID());
	erase(Player);
	delete Player;
}

void PlayerManager::AssignPlayerID( UINT32 ID )
{
	boost::lock_guard<boost::mutex> guard(_lock);
	_playerIDs.push(ID);
}