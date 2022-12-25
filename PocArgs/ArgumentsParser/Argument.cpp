#include "Argument.h"
#include <iostream>

Argument::Argument() {}

Argument::Argument(const std::string& name, ArgumentType argumentType, const std::string& shortoption, const std::string& longoption, const std::string& defaultValue, bool required, const std::string& help)
	: name(name),
	argumentType(argumentType),
	shortoption(shortoption),
	longoption(longoption),
	defaultValue(defaultValue),
	required(required),
	value(defaultValue),
	help(help)
{

}


int Argument::parse(int argc, char* argv[], int current_index) {

	if (this->argumentType == ArgumentType::BooleanSwitchArgument) {
		// Parsing BooleanSwitchArgument
		if (current_index <= (argc-1)) {
			if ((argv[current_index] == this->shortoption) || (argv[current_index] == this->longoption)) {
				current_index += 1;
				this->value = "true";
			}
			else {
				this->value = "false";
			}
		}
	}
	else if (this->argumentType == ArgumentType::StringArgument) {
		// Parsing StringArgument
		if (current_index <= (argc-2)) {
			if ((argv[current_index] == this->shortoption) || (argv[current_index] == this->longoption)) {
				this->value = argv[current_index + 1];
				current_index += 2;
			}
		}
	}
	else if (this->argumentType == ArgumentType::IntegerArgument) {
		// Parsing IntegerArgument

	}
	else if (this->argumentType == ArgumentType::PositionalIntegerArgument) {
		// Parsing PositionalIntegerArgument

	}
	else if (this->argumentType == ArgumentType::PositionalStringArgument) {
		// Parsing PositionalStringArgument
		if (current_index <= (argc - 1)) {
			this->value = argv[current_index];
			current_index += 1;
		}
	}
	return current_index;
}