#include "ClientEntityManager.h"

ClientEntityManager::~ClientEntityManager(void)
{
}

ClientEntity * ClientEntityManager::CreateEntity( BYTE Status,UINT32 RefID )
{
	return new ClientEntity(this,RefID,Status);
}