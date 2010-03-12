#pragma once
#include <boost/tr1/unordered_map.hpp>
#include "IOSystem.h"
class ConfigurationNode
{
	std::tr1::unordered_map<std::string,ConfigurationNode> subnodes;
public:
	std::string value;
};
class Configuration : ConfigurationNode
{
public:
	Configuration(void);
	~Configuration(void);
};
