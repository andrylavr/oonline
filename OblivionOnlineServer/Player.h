#pragma once
#include "entity.h"
#include "NetworkConnection.h"
class Player :
	public Entity, public NetworkConnection 
{
	friend class PlayerManager;
	Player(PlayerManager *manager,UINT32 ID,SOCKET network,boost::function<void (NetworkConnection *)>);
	~Player(void);
public:
};
