#include "Player.h"
#include "PlayerManager.h"
#include "EntityManager.h"

Player::Player(PlayerManager *manager, UINT32 ID,SOCKET network,boost::function<void (NetworkConnection *)> callback ) : Entity(manager->GetEntityManager(),ID),NetworkConnection(manager->GetEntityManager(),network,
																										callback)
{
}
Player::~Player(void)
{
}
