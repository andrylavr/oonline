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

namespace ChunkType{
	enum PkgChunk
	{
		Position = 2,
		CellID	 = 3,
		RPCRequest = 4,
		RPCReply = 5,
		Race     = 8,
		Class    = 9,
		Name     = 10,
		ActorValue= 11,
		ActorValueMod=12,
		Equip	 = 13,
		Chat     = 14,
		Auth	 = 15,
		ClientType = 16,
		Version	= 17,
		PlayerID = 18,
		Animation = 19,
		End
	};

};
class NetworkConnection;
class EntityManager;
typedef size_t (*ChunkHandler)(NetworkConnection *whom,EntityManager *ent,char *data,char *dataend);
namespace raw
{
struct Chunk
{
	UINT32 formID;
	BYTE chunkType;
};
struct ANSIString
{
	unsigned short strlen;
	char data[0];
	size_t Size() //String size, in bytes
	{
		return max(end-data,strlen)
	}
	std::string GetData(char *end)
	{
		return string(data,max(end-data,strlen));
	}
};
struct Position
{
	raw::Chunk header;
	static const ChunkType::PkgChunk Type= ChunkType::Position;
	static const bool Reliable=false;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
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
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::CellID;
	static const bool Reliable=true;
	UINT32 cellID;
	UINT32 WorldID; // NULL for Interiors
};
struct Race
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::Race;
	static const bool Reliable=true;
	UINT32 Value;
	BYTE IsFemale;
};
struct Class
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::Class;
	ANSIString Name;
};
struct Name
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::Name;
	ANSIString Value;
};
struct ActorValue
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::ActorValue;
	UINT8 code;
	short Value;
};
struct ActorValueMod
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::ActorValueMod;
	UINT8 code;
	short Value;
};
struct Equip
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::Equip;
	static const bool Reliable=true;
	UINT8 slot;
	UINT32 Value;
};
struct Chat
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::Chat;
	static const bool Reliable=true;
	ANSIString Message;
};
struct Auth 
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::Auth;
	static const bool Reliable=true;
	BYTE SHA512[64];
	ANSIString Data;
};
struct Animation
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::Animation;
	static const bool Reliable=true;
	BYTE AnimationGroup;
};
struct ClientType
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::ClientType;
	static const bool Reliable=true;
	BYTE IsMaster;
};
struct Version
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::Version;
	static const bool Reliable=true;
	BYTE super;
	BYTE major;
	BYTE minor;
	BYTE game;
};
struct PlayerID
{
	raw::Chunk header;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::PlayerID;
	static const bool Reliable=true;
	UINT32 ID;
};
struct RPCRequest //Experimental Script RPC.
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::RPCRequest;
	UINT32 functioncode; // 0x0 = Enumerate functions?
	UINT32 requestid; // To repeat requests, etc
	UINT16 seqno; // Which element of the parameters this request entails
	UINT16 seqsize;  //  Maximum number of requests 
	ANSIString Parameters; // Encoded parameters
};
struct RPCReply
{
	raw::Chunk header;
	static const bool Reliable=true;
	size_t Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd);
	static const ChunkType::PkgChunk Type= ChunkType::RPCReply;
	UINT32 requestid;
	UINT16 seqno; // Which element of the parameters this request entails
	UINT16 seqsize;  //  Maximum number of requests 
	ANSIString Results;
};
}

#pragma pack(pop)
using namespace ChunkType;
inline bool RequiresReliable(PkgChunk type)
{
	switch (type) // No breaks here

	{
	case	Position:
		return false;
	case CellID:
		return true;
	case Race:
		return true;
	case Class:
		return true;
	case Name:
		return true;
	case ActorValue:
		return true;
	case ActorValueMod:
		return true;
	case Equip:
		return true;
	case Chat:
		return true;
	case Auth:
		return true;
	case ClientType:
		return true;
	case Version:
		return true;
	case PlayerID:
		return true;
	case Animation:
		return false;

	default:
		return false;
	}
}
inline size_t GetMinChunkSize(PkgChunk type)
{
	switch(type)
	{
	case	Position:
		return sizeof(raw::Position);
	case CellID:
		return sizeof(raw::CellID);
	case Race:
		return sizeof(raw::Race);
	case Class:
		return sizeof(raw::Class);
	case Name:
		return sizeof(raw::Name);
	case ActorValueMod:
		return sizeof(raw::ActorValueMod);
	case ActorValue:
		return sizeof(raw::ActorValue);
	case Chat:
		return sizeof(raw::Chat);
	case Auth:
		return sizeof(raw::Auth);
	case ClientType:
		return sizeof(raw::ClientType);
	case Version:
		return sizeof(raw::Version);
	case PlayerID:
		return sizeof(raw::PlayerID);
	case Animation:
		return sizeof(raw::Animation);
	case Equip:
		return sizeof(raw::Equip);
	default:
		throw std::logic_error("Invalid Chunk Type!");
	}
}
size_t HandleChunk(NetworkConnection *net,EntityManager *ent,raw::Chunk *chunk,char *end)
{
	if(!net->GetPermissions().Match(chunk->formID,chunk->chunkType))
		throw ProtocolSecurityExcpetion(net,chunk->chunkType);
	switch(chunk->chunkType)
	{
	case ActorValue:
		return reinterpret_cast<raw::ActorValue*>(chunk)->Handle(net,ent,end);
	case ActorValueMod:
		return reinterpret_cast<raw::ActorValueMod*>(chunk)->Handle(net,ent,end);
	case Animation:
		return reinterpret_cast<raw::Animation*>(chunk)->Handle(net,ent,end);
	case Auth:
		return reinterpret_cast<raw::Auth*>(chunk)->Handle(net,ent,end);
	case CellID:
		return reinterpret_cast<raw::CellID*>(chunk)->Handle(net,ent,end);
	case Chat:
		return reinterpret_cast<raw::Chat*>(chunk)->Handle(net,ent,end);
	case Class:
		return reinterpret_cast<raw::Class*>(chunk)->Handle(net,ent,end);
	case ClientType:
		return reinterpret_cast<raw::ClientType*>(chunk)->Handle(net,ent,end);
	case Equip:
		return reinterpret_cast<raw::Equip*>(chunk)->Handle(net,ent,end);
	case Name:
		return reinterpret_cast<raw::Name*>(chunk)->Handle(net,ent,end);	
	case PlayerID:
		return reinterpret_cast<raw::PlayerID*>(chunk)->Handle(net,ent,end);
	case Position:
		return reinterpret_cast<raw::Position*>(chunk)->Handle(net,ent,end);
	case Race:
		return reinterpret_cast<raw::Race*>(chunk)->Handle(net,ent,end);
	case Version:
		return reinterpret_cast<raw::Version*>(chunk)->Handle(net,ent,end);
	default: 
		return 0;
	}
}

#define GAME_OBLIVION 1
#define GAME_FALLOUT3 2
