/*
Copyright 2008   Julian Bangert aka masterfreek64
This file is part of OblivionOnline.

OblivionOnline is free software; you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

OblivionOnline is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once
#include "GlobalDefines.h"
#include "Entity.h"
class NetworkConnection;
/*
OO Advanced Packet System:
Packets are streams of bytes transported either over an unreliable (UDP ) or a reliable (TCP) carrier:
Data is partitioned into chunks ( atomic information unit ): A network connection is a transparent, bidirectional stream of chunks
Every chunk contains 1 data , such as position on an axis , health , equipment in a slot , etc
Chunks that require reliability are sent over TCP , others can be sent on both , but usually are sent over UDP

Chunk Base Layout
BYTE	DATA
0-3		UINT32 FormID
4		Chunk Type

Strings in Packets:
ANSI strings are saved as follows:
unsigned short Length 
raw data 

Important Chunks
TYPE#	Description
0		Bad packet
1		Empty (old ObjectID)
2		Position . 6 floats : PosX, PosY, PosZ ,RotX,RotY,RotZ
3		CellID . One UINT32. UINT32 Worldspace.

4		RPCRequest
5		RPCReply
6		EMPTY
7		EMPTY
8		Race One Byte 1 if female and UINT32
9		Class  . ANSI string
10		Name   . ANSI string
11		ActorValue. BYTE AV Code and then short Value
12		ActorValueMod. BYTE AV COde and then short AV mod
13		Equip .  BYTE slot and UINT32 Equip
14		Chat	. ANSI string
15		Auth	. ANSI string Username , 512 bit SHA-512 
16		Client Type. BYTE : 0 if passive , 1 if master client. Passive is assumed until further notice ;)
17		Version .	SUPER , MAJOR AND MINOR as bytes. BYTE: GameID
18		PlayerID . UINT32 Player ID - sent only by server
19		Animation. BYTE Animation Group BYTE IsPlaying
*/
#pragma pack(push,1)
#define PAYLOAD_SIZE 3
#define PACKET_SIZE 1024
#define PACKET_HEADER_SIZE 3
enum PkgChunk
{
	pkg_Position = 2,
	pkg_CellID	 = 3,
	pkg_RPCRequest = 4,
	pkg_RPCReply = 5,
	pkg_Race     = 8,
	pkg_Class    = 9,
	pkg_Name     = 10,
	pkg_ActorValue= 11,
	pkg_ActorValueMod=12,
	pkg_Equip	 = 13,
	pkg_Chat     = 14,
	pkg_Auth	 = 15,
	pkg_ClientType = 16,
	pkg_Version	= 17,
	pkg_PlayerID = 18,
	pkg_Animation = 19,
	pkg_End
};
class ProtocolSecurityExcpetion : public std::runtime_error
{
public:
	ProtocolSecurityExcpetion(NetworkConnection *who,PkgChunk t): std::runtime_error("A protocol security violation was detected. Unauthorized Chunk.")
	{}
};
	
class EntityManager;
namespace raw
{
struct Chunk
{
	UINT32 formID;
	PkgChunk ChunkType;
};
#define MAX(x,y) ((x)>(y)?(x):(y))
struct ANSIString
{
	unsigned short strlen;
	char data[0];
	size_t Size(const char *end) const //String size, in bytes
	{
		return MAX(end-data,strlen);
	}
	std::string GetData(const char *end) const
	{
		return string(data,max(end-data,strlen));
	}
	void Write(const std::string &Message)
	{
		strlen= (unsigned short) MAX(Message.length(),65534); // DO not transmit a very long chat message ;)
		memcpy(data,Message.c_str(),strlen);
	}
};
struct Position
{
	raw::Chunk header;
	static const PkgChunk Type= pkg_Position;
	static const bool Reliable=false;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent);
	float PosX;
	float PosY;
	float PosZ;
	float RotX;
	float RotY;
	float RotZ;
};
struct CellID
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent);
	static const PkgChunk Type= pkg_CellID;
	static const bool Reliable=true;
	UINT32 cellID;
	UINT32 WorldID; // NULL for Interiors
};
struct Race
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent);
	static const PkgChunk Type= pkg_Race;
	static const bool Reliable=true;
	UINT32 Value;
	BYTE IsFemale;
};
struct Class
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent);
	static const PkgChunk Type= pkg_Class;
	ANSIString Name;
};
struct Name
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent);
	static const PkgChunk Type= pkg_Name;
	ANSIString Value;
};
struct ActorValue
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent,BYTE slot);
	static const PkgChunk Type= pkg_ActorValue;
	UINT8 code;
	short Value;
};
struct ActorValueMod
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent,BYTE slot);
	static const PkgChunk Type= pkg_ActorValueMod;
	UINT8 code;
	short Value;
};
struct Equip
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent,BYTE slot);
	static const PkgChunk Type= pkg_Equip;
	static const bool Reliable=true;
	UINT8 slot;
	UINT32 Value;
};
struct Chat
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent, std::string Message);
	static const PkgChunk Type= pkg_Chat;
	static const bool Reliable=true;
	ANSIString Message;
};
struct Auth 
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent, BYTE *SHA512,std::string Data);
	static const PkgChunk Type= pkg_Auth;
	static const bool Reliable=true;
	BYTE SHA512[64];
	ANSIString Data;
};
struct Animation
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent);
	static const PkgChunk Type= pkg_Animation;
	static const bool Reliable=true;
	BYTE AnimationGroup;
};
struct ClientType
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, UINT32 ent, BYTE IsMaster);
	static const PkgChunk Type= pkg_ClientType;
	static const bool Reliable=true;
	BYTE IsMaster;
};
struct Version
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent);
	static const PkgChunk Type= pkg_Version;
	static const bool Reliable=true;
	BYTE super;
	BYTE major;
	BYTE minor;
	BYTE game;
};
struct PlayerID
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static void Send(NetworkConnection &conn, Entity *ent,UINT32 ID);
	static const PkgChunk Type= pkg_PlayerID;
	static const bool Reliable=true;
	UINT32 ID;
};
struct RPCRequest //Experimental Script RPC.
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static const PkgChunk Type= pkg_RPCRequest;
	UINT32 functioncode; // 0x0 = Enumerate functions?
	UINT32 requestid; // To repeat requests, etc
	UINT16 seqno; // Which element of the parameters this request entails
	UINT16 seqsize;  //  Maximum number of packets this contains
	ANSIString Parameters; // Encoded parameters
};
struct RPCReply
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,const char *DataEnd)const;
	static const PkgChunk Type= pkg_RPCReply;
	UINT32 requestid;
	UINT16 seqno; // Which element of the parameters this request entails
	UINT16 seqsize;  //  Maximum number of requests 
	ANSIString Results;
};
}

#pragma pack(pop)
inline bool RequiresReliable(PkgChunk type)
{
	switch (type) // No breaks here

	{
	case	pkg_Position:
		return false;
	case pkg_CellID:
		return true;
	case pkg_Race:
		return true;
	case pkg_Class:
		return true;
	case pkg_Name:
		return true;
	case pkg_ActorValue:
		return true;
	case pkg_ActorValueMod:
		return true;
	case pkg_Equip:
		return true;
	case pkg_Chat:
		return true;
	case pkg_Auth:
		return true;
	case pkg_ClientType:
		return true;
	case pkg_Version:
		return true;
	case pkg_PlayerID:
		return true;
	case pkg_Animation:
		return false;

	default:
		return false;
	}
}
inline size_t GetMinChunkSize(PkgChunk type)
{
	switch(type)
	{
	case	pkg_Position:
		return sizeof(raw::Position);
	case pkg_CellID:
		return sizeof(raw::CellID);
	case pkg_Race:
		return sizeof(raw::Race);
	case pkg_Class:
		return sizeof(raw::Class);
	case pkg_Name:
		return sizeof(raw::Name);
	case pkg_ActorValueMod:
		return sizeof(raw::ActorValueMod);
	case pkg_ActorValue:
		return sizeof(raw::ActorValue);
	case pkg_Chat:
		return sizeof(raw::Chat);
	case pkg_Auth:
		return sizeof(raw::Auth);
	case pkg_ClientType:
		return sizeof(raw::ClientType);
	case pkg_Version:
		return sizeof(raw::Version);
	case pkg_PlayerID:
		return sizeof(raw::PlayerID);
	case pkg_Animation:
		return sizeof(raw::Animation);
	case pkg_Equip:
		return sizeof(raw::Equip);
	default:
		throw std::logic_error("Invalid Chunk Type!");
	}
}
size_t HandleChunk(NetworkConnection *net,EntityManager *ent,const raw::Chunk *chunk,const char *end);
#define GAME_OBLIVION 1
#define GAME_FALLOUT3 2

struct ChunkPermissions
{
	EntityPermission AV;
	EntityPermission Position;
	EntityPermission other;
	bool Match(UINT32 id,PkgChunk t) const 
	{
		switch (t)
		{
		case pkg_ActorValue:
			return AV == id;
		case pkg_Position:
		case pkg_Animation:
			return Position == id;
		default:
			return other == id;
		}
	}
	bool Match(Entity *ID,PkgChunk t)const
	{
		return Match(ID->RefID(),t);
	}
	ChunkPermissions(): AV(0,1),Position(0,1),other(0,1) // Keine schreibrechte 
	{
	}
};