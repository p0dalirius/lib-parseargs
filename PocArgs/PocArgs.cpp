#include <iostream>
#include "ArgumentsParser/ArgumentsParser.h"


ArgumentsParser parseArgs(int argc, char* argv[]) {
	ArgumentsParser parser = ArgumentsParser();

	parser.add_positional_string_argument("mode", "Operation mode");
	parser.add_positional_string_argument("another", "Another positional");
	
	parser.add_string_argument("target", "-t", "--target", "", true, "IP or adress of the target machine");
	parser.add_int_argument("port", "-p", "--port", "", true, "Port of the target machine");

	parser.add_boolean_switch_argument("verbose", "-v", "--verbose", false, false, "Verbose mode.");

	parser.parse_args(argc, argv);
	return parser;
}


int main(int argc, char* argv[])
{
	ArgumentsParser parser = parseArgs(argc, argv);

	if (std::get<bool>(parser.get_value("verbose")) == true) {
		std::cout << "[verbose] Mode verbose started.\n";
	}

	std::cout << std::get<int>(parser.get_value("port")) << "\n";

	parser.debug();
}
