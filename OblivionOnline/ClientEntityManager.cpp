#include "ClientEntityManager.h"

ClientEntityManager::~ClientEntityManager(void)
{
}

ClientEntity * ClientEntityManager::CreateEntity( UINT32 RefID )
{
	return new ClientEntity(this,RefID);
}