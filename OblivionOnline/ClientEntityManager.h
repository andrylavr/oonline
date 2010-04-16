#pragma once
#include "oocommon\entitymanager.h"
#include "ClientEntity.h"
class ClientEntityManager :
	public EntityManager
{
protected:
	virtual ClientEntity * CreateEntity(UINT32 RefID);
public:
	ClientEntityManager(IOStream *io) : EntityManager(io) {};
	~ClientEntityManager(void);
};

