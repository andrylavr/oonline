#pragma once
/*

Copyright(c) 2007-2008   Julian Bangert aka masterfreek64

This file is part of OblivionOnline.

OblivionOnline is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

OblivionOnline is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

*/
#include <string>
extern bool g_plot;
#include "GlobalDefines.h"

class IOStream;
class IOSystem;
class EntityManager;

class FakeClient
{
private:	
	IOSystem *IOSys;
			IOStream *IO;
			EntityManager *Entities;
			bool bIsConnected; //TCP / IP connection exists
			bool bIsMasterClient; // We have "write rigths" to the server entities
			bool bIsInitialized; // We received a player ID
			UINT32 LocalPlayer;
public:
	FakeClient(void);
	~FakeClient(void);
	void SetIsMasterClient(bool Value) {bIsMasterClient = Value;}
	void SetPlayerID(UINT32 value) {LocalPlayer = value; }
	EntityManager *GetEntities() {return Entities;}
	IOStream & GetIO(){return *IO;}
	void run();
	void HandleCommand(char * String);
};

extern FakeClient *g_fake;