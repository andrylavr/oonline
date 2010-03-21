#pragma once
#
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
#define DEFAULT_NUMBER_OF_THREADS 4
#include "GlobalDefines.h"
#include "threadpool.hpp"
class TaskHandler
{
	static TaskHandler _instance;
	TaskHandler(void);
	~TaskHandler(void);
	TaskHandler(const TaskHandler &other);
	boost::threadpool::pool pool; 
	/*static bool EndlessTrampoline(boost::function0<void> &t)
	{
		t();
		return true;
	} */
public:
	static TaskHandler & Instance()
	{
		return _instance;		
	}
	void ScheduleOnce(boost::function0<void> &Task)
	{
		pool.schedule(Task);
	}
	void ScheduleLoop(boost::function0<bool> &LoopTask,unsigned int mininterval)
	{
		pool.schedule(boost::threadpool::looped_task_func(LoopTask,mininterval));
	}
	/*
	void ScheduleEndlessLoop(boost::function0<void> &LoopTask,unsigned int mininterval)
	{
		pool.schedule(boost::threadpool::looped_task_func(boost::bind(EndlessTrampoline,LoopTask),mininterval );
	}*/
};
