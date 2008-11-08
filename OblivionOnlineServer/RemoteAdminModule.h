#pragma once

#include <string>
#include <list>

/* Remote admin is HTTP based and ought to output HTML code*/
class GameServer;

class RemoteAdminModule
{
protected:
	GameServer *m_gs;
public:
	RemoteAdminModule(GameServer *gs) {m_gs = gs; }
	~RemoteAdminModule(void) {}
	// Returns the Name in menus
	virtual const char *GetDisplayName() = 0;
	// Returns the name to be used in URLs, no spaces, only characters allowed in URLS
	virtual const char *GetName() = 0;
	// Data from a certain set of parameters Ought to be HTML
	virtual std::string * GetData(std::list<std::string> *parameters) = 0;
	virtual bool ShowInMenu() = 0;
	//AuthLevel MinAuthLevel;
};
