#include "ArgumentsParser.h"


int ArgumentsParser::parse_args(int argc, char* argv[]) {
	int current_arg_index = 1;
	bool show_help = false;
	bool mandatory_argument_found = false;

	if (argc < this->positionalArguments.size()) {
		show_help = true;
	} else {
		for (auto& arg_ptr : this->mandatoryArguments) {
			mandatory_argument_found = false;
			for (int k = 1; k < argc; k++) {
				if ((argv[k] == arg_ptr.shortoption) || (argv[k] == arg_ptr.longoption)) {
					mandatory_argument_found = true;
				}
			}
			if (mandatory_argument_found == false) {
				show_help = true;
			}
		}
	}

	if (show_help == true) {
		this->help(argc, argv);
		return -1;
	} else {
		// Parse positional arguments from the command line 
		for (auto& arg_ptr : this->positionalArguments) {
			current_arg_index = arg_ptr.parse(argc, argv, current_arg_index);
			this->arguments.insert({ arg_ptr.name, arg_ptr.value });
		}
		// Parse all other arguments from the command line
		for (auto& arg_ptr : this->allArguments) {
			current_arg_index = arg_ptr.parse(argc, argv, current_arg_index);
			this->arguments.insert({ arg_ptr.name, arg_ptr.value });
		}
		return 0;
	}
}


/* Add arguments */
void ArgumentsParser::add_positional_string_argument(const std::string& name, const std::string& help) {
	Argument arg = Argument(
		name, 
		ArgumentType::PositionalStringArgument, 
		(const std::string)"", 
		(const std::string)"", 
		(const std::string)"",
		true, 
		help
	);
	this->positionalArguments.push_back(arg);
}


void ArgumentsParser::add_boolean_switch_argument(const std::string& name, const std::string& shortoption, const std::string& longoption, bool defaultValue, bool required, const std::string& help) {
	Argument arg;
	if (defaultValue == false) {
		arg = Argument(
			name,
			ArgumentType::BooleanSwitchArgument,
			shortoption,
			longoption,
			"false",
			required,
			help
		);
	} else if (defaultValue == true) {
		arg = Argument(
			name,
			ArgumentType::BooleanSwitchArgument,
			shortoption,
			longoption,
			"true",
			required,
			help
		);
	}

	if (arg.required == true) {
		this->mandatoryArguments.push_back(arg);
	} else {
		this->optionalArguments.push_back(arg);
	}
	this->allArguments.push_back(arg);
}


void ArgumentsParser::add_string_argument(const std::string& name, const std::string& shortoption, const std::string& longoption, const std::string& defaultValue, bool required, const std::string& help) {
	Argument arg = Argument(
		name,
		ArgumentType::StringArgument,
		shortoption,
		longoption,
		defaultValue,
		required,
		help
	);
	if (arg.required == true) {
		this->mandatoryArguments.push_back(arg);
	}
	else {
		this->optionalArguments.push_back(arg);
	}
	this->allArguments.push_back(arg);
}


void ArgumentsParser::add_int_argument(const std::string& name, const std::string& shortoption, const std::string& longoption, const std::string& defaultValue, bool required, const std::string& help) {
	Argument arg = Argument(
		name,
		ArgumentType::IntegerArgument,
		shortoption,
		longoption,
		defaultValue,
		required,
		help
	);
	if (arg.required == true) {
		this->mandatoryArguments.push_back(arg);
	}
	this->allArguments.push_back(arg);
}


std::variant<bool, int, std::string> ArgumentsParser::getValue(char* argumentName) {

}


void ArgumentsParser::help(int argc, char * argv[]) {
	std::string programpath = ((std::string)argv[0]);
	std::string programname = programpath.substr(programpath.find_last_of("/\\") + 1);

	std::cout << "Usage: " << programname << " ";

	for (auto& arg_ptr : this->positionalArguments) {
		std::cout << "<" << arg_ptr.name << "> ";
	}

	this->allArguments.sort();
	for (auto& arg_ptr : this->allArguments) {
		std::cout << "[" << arg_ptr.shortoption << " " << arg_ptr.name << "] ";
	}
	std::cout << "\n\n";

	if (this->positionalArguments.size() != 0) {
		std::cout << "Positional arguments:\n";
		for (auto& arg_ptr : this->positionalArguments) {
			std::cout << "   <" << arg_ptr.name << ">   " << arg_ptr.help << "\n";
		}
		std::cout << "\n";
	}

	if (this->mandatoryArguments.size() != 0) {
		std::cout << "Required arguments:\n";
		for (auto& arg_ptr : this->mandatoryArguments) {
			std::cout << "   " << arg_ptr.shortoption << ", " << arg_ptr.longoption << " " << arg_ptr.help << "\n";
		}
		std::cout << "\n";
	}

	if (this->optionalArguments.size() != 0) {
		std::cout << "Optional arguments:\n";
		for (auto& arg_ptr : this->optionalArguments) {
			std::cout << "   " << arg_ptr.shortoption << ", " << arg_ptr.longoption << " " << arg_ptr.help << " (default: " << arg_ptr.defaultValue << ")" << "\n";
		}
		std::cout << "\n";
	}
}