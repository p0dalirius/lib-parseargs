#include "Argument.h"

Argument::Argument() {}

Argument::Argument(std::string name, std::string shortoption, std::string longoption, std::string defaultValue, bool required, std::string help) {
	this->name = name;
	this->shortoption = shortoption;
	this->longoption = longoption;
	this->defaultValue = defaultValue;
	this->value = defaultValue;
	this->help = help;
}