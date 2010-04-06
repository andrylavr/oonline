#pragma once
#include "GlobalDefines.h"
#include "Player.h"
#include <stack>
#include <set>
class Entity;
class EntityManager;
class NetworkSystem;
class PlayerManager : public std::set<Player *>
{
	boost::mutex _lock;
	std::stack<UINT32> _playerIDs;
	EntityManager *_mgr;
	NetworkSystem *_net;
	UINT32 m_MasterClient;	
public:
	void AssignPlayerID(UINT32 ID);
	Player *GetPlayer(SOCKET connection);
	void RemovePlayer(Player *Player);
	EntityManager *GetEntityManager(){ return _mgr;}
	PlayerManager(EntityManager *manager,NetworkSystem *Network);
	~PlayerManager(void);
};
