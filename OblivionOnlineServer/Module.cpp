#include "Module.h"
	//TODO: Add implementations
#include "GameServer.h"
#include "ModuleManager.h"
#include "ExternInterface.h"
#include "GameServer.h"
Module::Module(ModuleManager*mm, GameServer * gs,std::string Filename )
{
	InitialiseCallback callback;
	m_gs = gs;
	m_mm = mm;
#ifdef WIN32
	//load module
	//(sizeof(void *) == sizeof(HMODULE)); //static assert to verify the Win32 define of HMODULE
	Filename += ".dll";
	m_data = (void *)LoadLibraryA(Filename.c_str());
	callback = (InitialiseCallback) GetProcAddress((HMODULE)m_data,"OnLoad");
#endif
	plugin = callback(gs,VERSION_SUPER,VERSION_MAJOR,VERSION_MINOR);
	m_gs->GetEventSys()->DefaultEvents.EventLoadModule(this); 
	m_gs->GetIO() << BootMessage << "Module " << plugin->Name << " Version " << plugin->Version << " (" <<plugin->VersionName << " ) by "
		<< plugin->Author << "successfully loaded from file " << Filename << endl;
	plugin->PrintWelcome();
}
Module::~Module(void)
{
	m_gs->GetEventSys()->DefaultEvents.EventUnloadModule(this);
	if(plugin->shutdown)
		plugin->shutdown();
#ifdef WIN32
	FreeLibrary((HMODULE)m_data);
#endif
}
