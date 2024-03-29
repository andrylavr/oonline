#pragma once

#include <string>
#include <vector>

#include "obse/PluginAPI.h"

class PluginManager
{
public:
	PluginManager();
	~PluginManager();

	bool	Init(void);
	void	DeInit(void);

	PluginInfo *	GetInfoByName(const char * name);

	UInt32			GetNumPlugins(void);
	UInt32			GetBaseOpcode(UInt32 idx);
	PluginHandle	LookupHandleFromBaseOpcode(UInt32 baseOpcode);

	static bool			RegisterCommand(CommandInfo * _info);
	static void			SetOpcodeBase(UInt32 opcode);
	static void *		QueryInterface(UInt32 id);
	static PluginHandle	GetPluginHandle(void);

private:
	bool	FindPluginDirectory(void);
	void	InstallPlugins(void);

	struct LoadedPlugin
	{
		HMODULE		handle;
		PluginInfo	info;
		UInt32		baseOpcode;

		_OBSEPlugin_Query	query;
		_OBSEPlugin_Load	load;
	};

	typedef std::vector <LoadedPlugin>	LoadedPluginList;

	std::string			m_pluginDirectory;
	LoadedPluginList	m_plugins;

	static LoadedPlugin		* s_currentLoadingPlugin;
	static PluginHandle		s_currentPluginHandle;
};

extern PluginManager	g_pluginManager;

extern CommandInfo kCommandInfo_IsPluginInstalled;
extern CommandInfo kCommandInfo_GetPluginVersion;
