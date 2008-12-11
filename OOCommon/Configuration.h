#pragma once
#include <unordered_map>
#include "IOSystem.h"
class ConfigurationNode
{
	std::tr1::unordered_map<std::string,ConfigurationNode> subnodes;
public:
	
};
class Configuration : ConfigurationNode
{
public:
	Configuration(void);
	~Configuration(void);
};
