#include "PositionalArgument.h"

#include <iostream>

PositionalArgument::PositionalArgument() {}

PositionalArgument::PositionalArgument(std::string name, std::string help)
{
	this->name = name;
	this->help = help;
}