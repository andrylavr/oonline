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
)

include_directories( 
  "$(SolutionDir)../OOCommon"
)

add_definitions( 
  -DCURL_STATICLIB
  -D_CONSOLE
)
add_subdirectory( ../OOCommon/ commonbin )
add_executable( OblivionOnlineServer ${SOURCES} )

target_link_libraries( OblivionOnlineServer  OOCommon )