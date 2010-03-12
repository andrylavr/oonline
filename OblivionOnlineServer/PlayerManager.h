#pragma once
#include "GlobalDefines.h"
class Entity;
class PlayerManager : public std::list<Entity *>,public boost::mutex
{
public:
	Entity *GetNewPlayer();
	void RemovePlayer(Entity *Player);
	PlayerManager(void);
	~PlayerManager(void);
};
