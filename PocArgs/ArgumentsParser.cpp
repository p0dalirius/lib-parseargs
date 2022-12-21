#include "ArgumentsParser.h"


bool arguments_compare(Argument a, Argument b) {
	return a.name < b.name;
}


void ArgumentsParser::parse_args(int argc, char * argv[]) {
	unsigned int argpos = 0;

	if (argc <= this->positionalArguments.size()) {
		this->help(argc, argv);
	}
	
}


void ArgumentsParser::add_argument(Argument arg) {
	if (arg.required == true) {
		this->mandatoryArguments.push_back(arg);
		this->allArguments.push_back(arg);
	}
	else {
		this->optionalArguments.push_back(arg);
		this->allArguments.push_back(arg);
	}
}


void ArgumentsParser::add_positional_argument(Argument arg) {
	this->positionalArguments.push_back(arg);
}



void ArgumentsParser::help(int argc, char * argv[]) {
	std::string programpath = ((std::string)argv[0]);
	std::string programname = programpath.substr(programpath.find_last_of("/\\") + 1);

	std::cout << "Usage: " << programname << " ";

	for (std::list<Argument>::iterator it = this->positionalArguments.begin(); it != this->positionalArguments.end(); ++it) {
		std::cout << "<" << it->name << "> ";
	}

	this->allArguments.sort(arguments_compare);
	for (std::list<Argument>::iterator it = this->allArguments.begin(); it != this->allArguments.end(); ++it) {
		std::cout << "[" << it->shortoption << " " << it->name << "] ";
	}
	std::cout << "\n";
}