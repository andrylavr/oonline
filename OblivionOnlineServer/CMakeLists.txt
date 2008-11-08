project( OblivionOnlineServer )

set(SOURCES 
  MiscChunkHandler.cpp
  NetworkSystem.cpp
  GameServer.cpp
  ChatIOProvider.cpp
  ScreenIOProvider.cpp
  LuaSystem.cpp
  EntityUpdateManager.cpp
  lua/lapi.c
  lua/lauxlib.c
  lua/lbaselib.c
  lua/lcode.c
  lua/ldblib.c
  lua/ldebug.c
  lua/ldo.c
  lua/ldump.c
  lua/lfunc.c
  lua/lgc.c
  lua/linit.c
  lua/liolib.c
  lua/llex.c
  lua/lmathlib.c
  lua/lmem.c
  lua/loadlib.c
  lua/lobject.c
  lua/lopcodes.c
  lua/loslib.c
  lua/lparser.c
  lua/lstate.c
  lua/lstring.c
  lua/lstrlib.c
  lua/ltable.c
  lua/ltablib.c
  lua/ltm.c
  lua/lundump.c
  lua/lvm.c
  lua/lzio.c
  lua/print.c
  Event.cpp
  EventSystem.cpp
  Module.cpp
  ModuleManager.cpp
  ModuleAdminModule.cpp
  PlayerAdminModule.cpp
  RemoteAdminServer.cpp
  main.cpp
)

include_directories( 
  "$(SolutionDir)../OOCommon"
)

add_definitions( 
  -DCURL_STATICLIB
  -D_CONSOLE
  -D_DEBUG
)

add_executable( OblivionOnlineServer WIN32 ${SOURCES} )

target_link_libraries( OblivionOnlineServer  OOCommon )
