#ifndef _OO_GUID_H
#define _OO_GUID_H
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
#pragma pack (push,2)
struct OOUUID{ // this is a 64-bit tuned implementation of GUID
	UInt32 Data1;
	UInt16 Data2;
	UInt16 Data3;
	UInt64 Data4;
	public bool operator==(OOUUID& other)
	{
		return ((UInt64)other == (*(UInt64 *)this)) && 
			   *(((UInt64 *)&other) +1) == (*(UInt64 *)&Data3); //Convert to 2 64 bit integers
		//Makes comparison REALLY fast
	}
	public OOUUID& operator=(OOUUID& other)
	{
		*((UInt64 *)&Data1) = *(UInt64 *)&other; // copy it in the form of 2 64 bit integers
		*((UInt64 *) &Data3)= *(((UInt64 *)other)+1); 
		return *this;
	}
};
#pragma pack(pop)
#endif