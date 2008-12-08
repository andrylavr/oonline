/*
This file is part of OblivionOnline Server- An open source game server for the OblivionOnline mod
Copyright (C)  2008   Julian Bangert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.


You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "IOSystem.h"
#include "IOProvider.h"


bool IOSystem::RegisterIOProvider(IOProvider *provider)
{
	lock.lock();
	//so no IO system is contained twice
	m_providers.remove(provider);//TODO: Not thread-safe
	m_providers.push_back(provider);
	lock.unlock();
	return true;
}
bool IOSystem::RemoveIOProvider(IOProvider *system)
{
	lock.lock();
	m_providers.remove(system);
	lock.unlock();
	return true;
}

bool IOSystem::RegisterInput(std::string *Message)
{
	delete(Message);
	return true;
}

bool IOSystem::DoOutput( LogLevel Level,std::string & Message )
{
	for(std::list<IOProvider *>::iterator  iter = m_providers.begin(); iter != m_providers.end(); iter++)
	{
		(*iter)->DoOutput(Level,Message);
	}
	return true;
}

IOSystem::~IOSystem( void )
{
	for(std::list<IOProvider *>::iterator  iter = m_providers.begin(); iter != m_providers.end(); iter++)
	{
		delete (*iter);
	}
	m_providers.clear();
	delete[] m_buf;
}

int IOSystem::sync( void )
{
	if(m_buf[0] == '\0')
		return 0;
	lock.lock();
	time_t timestamp = time(NULL);
	//TODO: make this a static alloc as class member. is that faster??
	std::string * Message = new std::string(ctime(&timestamp),24);
	switch(DefaultLogLevel)
	{
	case BootMessage:
		*Message +="[BootMessage]";
		break;
	case Error:
		*Message +="[Error]";
		break;
	case SystemMessage:
		*Message +="[SystemMessage]";
		break;
	case GameMessage:
		*Message +="[GameMessage]";
		break;
	case Warning:
		*Message +="[Warning]";
		break;
	case FatalError:
		*Message +="[FatalError]";
		break;
	case PlayerChat:
		*Message +="[PlayerChat]";
		break;
	case AdminChat:
		*Message +="[Admin]";
		break;
	default:
		*Message +="[unknown]";
		break;
	}
	Message->append(pbase(),pptr() - pbase());
	int ret = (int) DoOutput(DefaultLogLevel,*Message);
	DefaultLogLevel = LogLevel::SystemMessage;
	delete Message;
	// reset the buffer
	m_buf[0] = '\0';
	setp(pbase(), epptr());
	lock.unlock();
	return 0;
}