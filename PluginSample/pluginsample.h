#pragma once
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
#ifndef PLUGINSAMPLE_H
#define PLUGINSAMPLE_H
#include "ExternInterface.h"
#include <boost/signal.hpp>
// Our overloaded Plugin Info. this is a very important tool a plugin can use to publish information
class PluginSampleInfo : public PluginInfo
{
public:
	PluginSampleInfo() : PluginInfo()
	{ } 
	boost::signal<void()> RandomCallbackEvent;
};
extern GameServer *g_gs;
void LoadInteropSample(); // this is a function that will act a bit like a second plugin
// I  hate having to make 2 examples, so this is it. It will not interact with the other plugin directly (except by using its gameserver instance)
// but it will register on the random callback event
#endif