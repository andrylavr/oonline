#pragma once
//WAS DEEMED UNECESSARY, maybe restore sometime
#if 0 
#include "GlobalDefines.h"
#include "Packets.h"
class ChunkParser;
class BaseChunk
{
protected:
	NetworkConnection *buffer;
	
	Chunk(NetworkBuffer *buf){}
	~Chunk(void);

public:
	virtual void Handle(IOStream *IO,GameServer *entities,Entity *ent,NetworkConnection *from) = 0;
};
template <typename rawCHUNK> class Chunk
{
	Chunk(const Chunk &other){assert("Copy constructor hit"==0);}
protected:
	rawCHUNK *data;
	Chunk(NetworkConnection *buf,rawCHUNK *Data,UINT32 FormID):BaseChunk(buf),data(Data);
	{
		data->header.chunkType = rawCHUNK::Type;
		data->formID = FormID;
	}
	~Chunk()
	{}	
};
namespace Chunk{
class ActorValue:public Chunk<raw::ActorValue>
{
public:
	ActorValue(NetworkConnection *buf,char *data,UINT32 FormID,BYTE code,short Value) :
	  Chunk<raw::ActorValue>(buf,(raw::ActorValue*)data,FormID),data->code(code),data->Value(Value)
	{}
	BYTE Code() const
	{
		return data->code;
	}
	short Value() const
	{
		return data->Value;
	}
};
class Animation:public Chunk<raw::Animation>
{
public:
	BYTE Code() const
	{
		return data->AnimationGroup;
	}
	Animation(NetworkConnection *buf,char *data,UINT32 FormID,BYTE Code):Chunk<raw::Animation>(buf,(raw::Animation*)data,FormID),data->AnimationGroup(Code)
	{}
};
class Position:public Chunk<raw::Position>
{
public:
	float PosX()const{return data->PosX;}
	float PosY()const{return data->PosY;}
	float PosZ()const{return data->PosZ;}
	float RotX()const{return data->RotX;}
	float RotY()const{return data->RotY;}
	float RotZ()const{return data->RotZ;}
	Position(NetworkConnection *buf,char *data,float PosX,float PosY,float PosZ,float RotX,float RotY,float RotZ):
	Chunk<raw::Position>(buf,(raw::Position*)data,data->AnimationGroup()
};
}
#endif