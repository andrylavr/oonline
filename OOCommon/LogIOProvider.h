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
#include "IOProvider.h"
#include <boost/thread.hpp>
#include <fstream>
#include <ios>
#include <ctime>
class LogIOProvider :
	public IOProvider
{
	boost::mutex _lock;
public:
	LogIOProvider(IOSystem *parent,LogLevel threshold, std::string FileName): IOProvider(parent),_lock(),File(NULL)
	{
		boost::unique_lock<boost::mutex>(_lock);
		File= fopen(FileName.c_str(),"w");
		if(File)
		{
			time_t timestamp = time(NULL);
			fwrite(ctime(&timestamp),24,1,File);
			fputc((int)'\t',File);
			fprintf(File,"Opened Log File");
			fflush(File);
		}
		m_filename = FileName;
		m_threshold = threshold;
	}
	~LogIOProvider(void)
	{
		if(File)
		{
			time_t timestamp = time(NULL);
			fwrite(ctime(&timestamp),24,1,File);
			fputc((int)'\t',File);
			fprintf(File,"Closing Log");
			fputc((int)'\n',File);
			fclose(File);
		}
	}
	bool DoOutput(LogLevel LogLevel,const std::string & Message)
	{
		if(LogLevel < m_threshold)
			return false;
		if(File)
		{
			boost::unique_lock<boost::mutex>(_lock);
			fwrite(Message.c_str(),Message.length(),1,File);
			fputc((int)'\n',File);
			fflush(File);
		}
		return true;
	}
private:
	FILE *File;
	std::string m_filename;
	LogLevel m_threshold;
};
