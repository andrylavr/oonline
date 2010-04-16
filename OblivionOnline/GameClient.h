#pragma once
/*

Copyright(c) 2007-2010   Julian Bangert 

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
#include <deque>
#include <iostream>
#include <unordered_set>
#include "IOSystem.h"
#include "ClientEntityManager.h"
class OutPacketStream;
class ClientEntity;
extern bool g_bRenderGUI;
class GameClient
{
private:
	std::deque<Entity *> UpdateQueue;

	NetworkConnection *conn;
	ClientEntityManager *Entities;
	bool bIsConnected; //TCP / IP connection exists
	bool bIsMasterClient; // We have "write rigths" to the server entities
	bool bIsInitialized; // We received a player ID
	
	UINT32 LocalPlayer;
	UINT32 TotalPlayers;

	HANDLE hRecvThread;
	SOCKET ServerSocket;
	std::tr1::unordered_set<UINT32> ignore;
	char ServerIP[15];
public:
	GameClient(void);
	~GameClient(void);
	int Initialize();
	int Deinitialize();
	bool Connect();
	void Disconnect();
	ClientEntityManager *GetEntities()
	{
		return Entities;
	}
	UINT32 GetLocalPlayer()
	{
		return LocalPlayer;
	}
	bool GetIsConnected()
	{
		return bIsConnected;
	}
	/*returns if the client is ready for operation, a.k.a. player ID received*/
	bool GetIsInitialized()
	{
		return bIsInitialized;
	}
	bool GetIsMasterClient()
	{
		return bIsMasterClient;
	}
	std::deque<Entity *> *GetUpdateQueue()
	{
		return &UpdateQueue;
	}
	void SetPlayerID(UINT32 Value);
	void SetIsMasterClient(bool Value)
	{
		bIsMasterClient = Value;
	}
	void IgnoreRefID(UINT32 Value);// to register OO pure ref IDs;
	bool IsRefIDIgnore(UINT32 Value);
	bool SetRenderGUI(bool Value)
	{
		return g_bRenderGUI = Value;
	}
	bool GetRenderGUI()
	{
		return g_bRenderGUI;
	}

	NetworkConnection &GetConnection()
	{
		return *conn;
	}
	//Returns invalid pointer if entity does not exist
	bool RunFrame();
	bool EmptyPlayerCell();
};

