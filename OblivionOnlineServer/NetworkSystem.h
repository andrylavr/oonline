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
#pragma once

#include "OutPacket.h"
#include "GlobalDefines.h"
#ifndef WIN32
#include <netdb.h>
#endif
#include <set>
#include <ctime>
#include "GameServer.h"
class NetworkSystem
{
private:
	bool _work;
	boost::condition_variable _work_notify;
	boost::mutex _listlock;
	std::set<NetworkConnection *> _connections;
	boost::thread _tcp;
	GameServer *m_GS;
	void AcceptThread();
	void AddPlayer(SOCKET sock);
	NetworkSystem(const NetworkSystem &other)
	{
		throw std::logic_error("Networksystem noncopiable");
	}
public:
	void OnDisconnect(NetworkConnection *ptr);
	NetworkSystem(GameServer *Server);
	~NetworkSystem(void);
	void Start() { _work = true; _work_notify.notify_all();}
	GameServer * GetGS()
	{
		return m_GS;
	}
};
