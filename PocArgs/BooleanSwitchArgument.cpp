#include "BooleanSwitchArgument.h"
#include <string>


BooleanSwitchArgument::BooleanSwitchArgument(std::string name, std::string shortoption, std::string longoption, bool defaultValue, bool required, std::string help)
{
	this->name = name;
	this->shortoption = shortoption;
	this->longoption = longoption;
	this->defaultValue = defaultValue;
	this->value = defaultValue;
	this->help = help;
}