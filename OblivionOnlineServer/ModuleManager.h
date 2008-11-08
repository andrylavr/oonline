#pragma once
#include "Module.h"
#include "EventSystem.h"
#include <list>

class ModuleManager
{
public:
	ModuleManager(GameServer *gs);
	~ModuleManager(void);
	void AddModule(Module *m_mod)
	{
		m_Modules.push_back(m_mod);
	}
	void LoadModule(std::string Filename)
	{
		AddModule(new Module(this,m_gs,Filename));
	}
	Module * FindModule(GUID guid)
	{		
		for(std::list<Module *>::iterator m_iter = m_Modules.begin() ; m_iter != m_Modules.end(); m_iter++)
		{
			if((*m_iter)->GetGUID() == guid)
				return *m_iter;
		}
	}
	std::list<Module *>::iterator BeginIter()
	{
		return m_Modules.begin();
	}
	std::list<Module *>::iterator EndIter()
	{
		return m_Modules.end();
	}


	//Module * FindModule(std::string Name);
private:
	std::list<Module *> m_Modules;
	GameServer *m_gs;
};
