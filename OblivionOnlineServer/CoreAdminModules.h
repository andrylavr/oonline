
#include "RemoteAdminModule.h"

class ModuleAdminModule : public RemoteAdminModule
{
public:
	virtual const char *GetDisplayName();
	// Returns the name to be used in URLs, no spaces, only characters allowed in URLS
	virtual const char *GetName();
	// Data from a certain set of parameters Ought to be HTML
	virtual std::string * GetData(std::list<std::string> *parameters);
	virtual bool ShowInMenu();
	ModuleAdminModule(GameServer *gs) : RemoteAdminModule(gs) {}
	~ModuleAdminModule() {}
};
class PlayerAdminModule : public RemoteAdminModule
{
public:
	virtual const char *GetDisplayName();
	// Returns the name to be used in URLs, no spaces, only characters allowed in URLS
	virtual const char *GetName();
	// Data from a certain set of parameters Ought to be HTML
	virtual std::string * GetData(std::list<std::string> *parameters);
	virtual bool ShowInMenu();
	PlayerAdminModule(GameServer *gs) : RemoteAdminModule(gs) {}
	~PlayerAdminModule() {}
};
