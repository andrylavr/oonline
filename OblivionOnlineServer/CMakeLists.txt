project( OblivionOnlineServer )

set(SOURCES 
ChatIOProvider.cpp
EntityUpdateManager.cpp
Event.cpp
EventSystem.cpp
GameServer.cpp
LuaSystem.cpp
main.cpp
MiscChunkHandler.cpp
ModuleAdminModule.cpp
Module.cpp
ModuleManager.cpp
NetworkSystem.cpp
panic.cpp
PlayerAdminModule.cpp
RemoteAdminServer.cpp
ScreenIOProvider.cpp
../OOCommon/EntityManager.cpp                                                                                                                                              
../OOCommon/IOSystem.cpp
../OOCommon/LogIOProvider.cpp
../OOCommon/NetSendActorValue.cpp
../OOCommon/NetSendChat.cpp
../OOCommon/NetSendEquip.cpp
../OOCommon/NetSendPosition.cpp
../OOCommon/NetworkSystem.cpp
../OOCommon/OOHashTable.cpp
../OOCommon/ObjectChunkHandler.cpp
../OOCommon/OutPacketStream.cpp
../OOCommon/PositionChunkHandler.cpp
../OOCommon/StatChunkHandler.cpp
../OOCommon/lua/lapi.c
../OOCommon/lua/lauxlib.c
../OOCommon/lua/lbaselib.c
../OOCommon/lua/lcode.c
../OOCommon/lua/ldblib.c
../OOCommon/lua/ldebug.c
../OOCommon/lua/ldo.c
../OOCommon/lua/ldump.c
../OOCommon/lua/lfunc.c
../OOCommon/lua/lgc.c
../OOCommon/lua/linit.c
../OOCommon/lua/liolib.c
../OOCommon/lua/llex.c
../OOCommon/lua/lmathlib.c
../OOCommon/lua/lmem.c
../OOCommon/lua/loadlib.c
../OOCommon/lua/lobject.c
../OOCommon/lua/lopcodes.c
../OOCommon/lua/loslib.c
../OOCommon/lua/lparser.c
../OOCommon/lua/lstate.c
../OOCommon/lua/lstring.c
../OOCommon/lua/lstrlib.c
../OOCommon/lua/ltable.c
../OOCommon/lua/ltablib.c
../OOCommon/lua/ltm.c
../OOCommon/lua/lundump.c
../OOCommon/lua/lvm.c
../OOCommon/lua/lzio.c
../OOCommon/lua/print.c



)

set( Boost_LIBRARIES
	boost_date_time
	boost_thread
	boost_signals
)
include_directories(
  	"/usr/include"
	"/usr/local/include"
	"../OOCommon/"
)

add_definitions( 
  -DCURL_STATICLIB
  -D_CONSOLE
)
link_directories ( /lib/ /usr/lib/ /usr/local/lib ) 
add_executable( OblivionOnlineServer ${SOURCES} )
target_link_libraries( OblivionOnlineServer ${Boost_LIBRARIES})


#link_directories( commonbin )
#target_link_libraries( OblivionOnlineServer  OOCommon )
