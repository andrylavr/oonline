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
#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <streambuf>
#include <ctime>
#include <ostream>
#include <iostream>
#include <boost/thread.hpp>
class IOProvider;
enum LogLevel
{
	BootMessage =1 ,
	SystemMessage,
	GameMessage,
	Warning,
	Error,
	FatalError,
	PlayerChat,
	AdminChat,
	AdminCommand,
	MaxLogLevel
};
class IOSystem : public std::streambuf
{
public:
	static boost::mutex lock;
	LogLevel DefaultLogLevel;
	static IOSystem &Instance()
	{
		static boost::thread_specific_ptr<IOSystem> _instance;
		if(!_instance.get()) _instance.reset(new IOSystem());
		return *_instance;
	}
	bool DoOutput(LogLevel Level,const std::string & Message);
	bool DoOutput(LogLevel Level,char * Message)
	{
		return DoOutput(Level,std::string(Message));
	} 
	bool DoOutput(LogLevel Level,char *Message,size_t MessageLen)
	{
		return DoOutput(Level,std::string(Message,MessageLen));
	}
	bool RegisterIOProvider(IOProvider *provider);
	bool RemoveIOProvider(IOProvider *system);
	bool RegisterInput(std::string  *Message);//TODO : tune performance here , the input still locks 
	~IOSystem(void);
protected:
	static std::list <IOProvider *> m_providers;
private:
	IOSystem();
	char *m_buf;
	size_t m_buflen;
	virtual int sync (void);
	int overflow (int c) {
		lock.lock();
		// allocate a new buffer and copy
		// our current data into it, then swap
		// it with the old buffer
		m_buflen += 1024;
		char * newbuf = new char[m_buflen];
		memcpy(newbuf, m_buf, m_buflen-1024);
		delete[] m_buf;
		m_buf = newbuf;
		setp(m_buf, m_buf + m_buflen);
		// now we need to stuff c into the buffer
		sputc(c);
		lock.unlock();
		return 0;
	}
};
class IOStream : public std::ostream {
public:
	static IOStream & Instance()
	{
		static boost::thread_specific_ptr<IOStream> _instance ;
		if(!_instance.get()) _instance.reset(new IOStream());
		return *_instance;
	}
	// we initialize the ostream to use our logbuf

	inline bool RegisterIOProvider(IOProvider *provider)
	{
		return IOSystem::Instance().RegisterIOProvider(provider);
	}
	inline bool RemoveIOProvider(IOProvider *provider)
	{
		return IOSystem::Instance().RemoveIOProvider(provider);
	}
	inline bool RegisterInput(std::string  *Message)
	{
		return IOSystem::Instance().RegisterInput(Message);
	}
	  // set priority
	  void SetLogLevel (LogLevel lvl) {
		  IOSystem::Instance().DefaultLogLevel = lvl; 
	  }

private:
	IOStream(): std::ostream(&IOSystem::Instance())
	{
	}
};
inline IOStream& operator<< (IOStream& ls,
					   LogLevel lvl) 
{
						   ls.SetLogLevel(lvl);
						   return ls;
}
