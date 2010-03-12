/*

Copyright(c) 2007-2010   Julian Bangert aka masterfreek64

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

Linking OblivionOnline statically or dynamically with other modules is making a combined work based
on OblivionOnline. Thus, the terms and conditions of the GNU Affero General Public License cover 
the whole combination.

In addition, as a special exception, the copyright holders of  OblivionOnline give you permission to 
combine OblivionOnline program with free software programs or libraries that are released under
the GNU LGPL and with code included in the standard release of Oblivion Script Extender by Ian Patterson (OBSE)
under the OBSE license (or modified versions of such code, with unchanged license). You may copy and distribute such a system 
following the terms of the GNU GPL for  OblivionOnline and the licenses of the other code concerned,
provided that you include the source code of that other code when and as the GNU GPL
requires distribution of source code.

Note that people who make modified versions of  OblivionOnline are not obligated to grant this special exception
for their modified versions; it is their choice whether to do so. 
The GNU Affero General Public License gives permission to release a modified version without this
exception; this exception also makes it possible to release a modified version which carries 
forward this exception.
*/
// Contains chunk handling functions
#include "GlobalDefines.h"
#include "Packets.h"
size_t raw::Position::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::Position ==  header.chunkType);
	Entity *ent=manager->GetOrCreateEntity(header.formID);
	if(!ent) throw std::runtime_error("Could not create Entity");
	ent->Move(PosX,PosY,PosZ,true);
	return sizeof(*this);
}

size_t raw::CellID::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::CellID == header.chunkType);
	Entity * ent=manager->GetOrCreateEntity(header.formID);
	if(!ent) throw std::runtime_error("Could not create Entity");
	ent->SetCell(cellID,WorldID,true);
	return sizeof(*this);
}
size_t raw::Race::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::Race == header.chunkType);
	Entity * ent=manager->GetOrCreateEntity(header.formID);
	if(!ent) throw std::runtime_error("Could not create Entity");
	ent->SetRace(Value,true);
	return sizeof(*this);
}
size_t raw::Class::Handle(NetworkConnection *who,EntityManager *manager,char *DataEnd)
{
	assert(ChunkType::Class == header.chunkType);
	Entity * ent=manager->GetOrCreateEntity(header.formID);
	if(!ent) throw std::runtime_error("Could not create Entity");
	ent->SetClassName(Name.GetData(),true);
	return sizeof(*this)+Name.Size();
}

size_t raw::Name::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::Name == header.chunkType);
	Entity * ent=manager->GetOrCreateEntity(header.formID);
	if(!ent) throw std::runtime_error("Could not create Entity");
	ent->SetName(Value.GetData(),true);
	return sizeof(*this)+Value.Size();
}

size_t raw::ActorValue::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::ActorValue== header.chunkType);
	Entity * ent=manager->GetOrCreateEntity(header.formID);
	if(!ent) throw std::runtime_error("Could not create Entity");
	ent->SetActorValue(code,Value);
	return sizeof(*this);
}

size_t raw::ActorValueMod::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::ActorValueMod == header.chunkType);
	Entity * ent=manager->GetOrCreateEntity(header.formID);
	if(!ent) throw std::runtime_error("Could not create Entity");
	ent->SetActorValueMod(code,Value);
	return sizeof(*this);
}

size_t raw::Equip::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::Equip == header.chunkType);
	Entity * ent=manager->GetOrCreateEntity(header.formID);
	if(!ent) throw std::runtime_error("Could not create Entity");
	ent->SetEquip(slot,Value,true);
	return sizeof(*this);
}

size_t raw::Chat::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::Chat == header.chunkType);
	Entity * ent=manager->GetOrCreateEntity(header.formID);
	if(!ent) throw std::runtime_error("Could not create Entity");
	ent->Chat(Message.GetData(),true);
	return sizeof(*this)+Message.Size();
}

size_t raw::Auth::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::Auth == header.chunkType);
	return sizeof(*this);
}

size_t raw::Animation::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::Animation == header.chunkType);
	Entity * ent=manager->GetOrCreateEntity(header.formID);
	if(!ent) throw std::runtime_error("Could not create Entity");
	ent->SetAnimation(AnimationGroup,true,true);//TODO: refactor
	return sizeof(*this);
}

size_t raw::ClientType::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::ClientType == header.chunkType);
	assert(0); // Not implemented
	return sizeof(*this);
}

size_t raw::Version::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
	assert(ChunkType::Version == header.chunkType);
	if(super!=VERSION_SUPER|| minor!=VERSION_MINOR|| major!=VERSION_MAJOR) return NULL; // Drop if version missmatch
	return sizeof(*this)+Value.Size();
}

size_t raw::PlayerID::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{
}

size_t raw::RPCRequest::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{

}

size_t raw::RPCReply::Handle( NetworkConnection *who,EntityManager *manager,char *DataEnd )
{

}