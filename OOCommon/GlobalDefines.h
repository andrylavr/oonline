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
#ifndef _GLOBAL_DEFINES_H
#define _GLOBAL_DEFINES_H

#include <boost/thread.hpp>
#include <boost/thread/locks.hpp>
#include <boost/signal.hpp>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
#define VERSION_SUPER 0
#define VERSION_MAJOR 4
#define VERSION_MINOR 9
#define VERSION_CODENAME "Release V"
#define VERSION_COMMENT "Public Beta 1"
#define VERSION_CODE ( VERSION_SUPER*1000000 + VERSION_MAJOR *1000+VERSION_MINOR )
#define VERSION_STREAM VERSION_SUPER<<"."<<VERSION_MAJOR<<"."<<VERSION_MINOR<<" \""<< VERSION_CODENAME << " \" "<< VERSION_COMMENT << " "  
#ifdef WIN32
#include <Windows.h>
typedef HANDLE OO_THREAD;
typedef void OO_TPROC_RET;
#ifdef OO_EXPORT
	#define OO_API __declspec(dllexport)
#else
	#define OO_API __declspec(dllimport)
#endif
#else
#include <stdint.h>
extern "C" {
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
}
#define OO_API 
typedef uint64_t UINT64;
typedef uint32_t UINT32;
typedef uint32_t DWORD;
typedef int32_t OO_THREAD;
typedef uint16_t UINT16;
typedef uint8_t UINT8;
typedef uint8_t BYTE;
typedef int16_t INT16; 

typedef void * OO_TPROC_RET;
typedef int SOCKET;
typedef sockaddr_in SOCKADDR_IN;
//typedef HANDLE SEMAPHORE;
#include <sys/select.h>
#include <sys/socket.h>
typedef int SOCKET;
typedef fd_set FD_SET;
typedef struct sockaddr SOCKADDR;
#define SOCKET_ERROR -1
#define closesocket close
#endif

#endif
using namespace std;
#define MAX_EQUIPSLOTS 18
#define MAX_PLAYERS 12
/* IN CLOCK_TIMERS 
1000/60 - (FPS maximum you can get with VSynch) */
#define RESEND_TICK 16
