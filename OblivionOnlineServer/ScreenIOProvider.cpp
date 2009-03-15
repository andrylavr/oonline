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
#include "ScreenIOProvider.h"
ScreenIOProvider::ScreenIOProvider(IOSystem *parent,LogLevel LogThreshold) : IOProvider(parent)
{
	m_threshold = LogThreshold;
	#ifdef WIN32
	TextColour[BootMessage] = FOREGROUND_BLUE | FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_INTENSITY;
	TextColour[SystemMessage] = FOREGROUND_BLUE | FOREGROUND_GREEN; // cyan
	TextColour[GameMessage] = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY; // strong cyan
	TextColour[Warning] = FOREGROUND_RED;
	TextColour[Error] = FOREGROUND_RED | FOREGROUND_INTENSITY;
	TextColour[FatalError] = FOREGROUND_RED | FOREGROUND_INTENSITY;
	TextColour[PlayerChat] = FOREGROUND_GREEN;
	TextColour[AdminChat] = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	TextColour[AdminCommand] = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
	TextColour[MaxLogLevel] = FOREGROUND_BLUE | FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_INTENSITY;
	#endif
}
void SetStdOutColor(int clr)
{
#ifdef WIN32
	WORD color;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO buf;
	if(GetConsoleScreenBufferInfo(console,&buf))
	{
		color = (buf.wAttributes & 0xF0) + (clr & 0x0F);
		SetConsoleTextAttribute(console,clr);
	}
	return;
#else
#warning "your platform does not support coloured output"
#endif
}
OO_TPROC_RET ScreenIOProvider::QueryProc(ScreenIOProvider *thisptr)
{
	std::string *msg;
	while(1)
	{
		msg = new std::string (); //TODO : Handle deletion of this
		std::cin >> (*msg);
		thisptr->GetIOSystem()->RegisterInput(msg);
	}
		
}
