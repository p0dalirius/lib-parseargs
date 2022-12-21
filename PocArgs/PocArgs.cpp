#include <iostream>
#include "ArgumentsParser.h"


void parseArgs(ArgumentsParser parser, int argc, char* argv[]) {
	parser.add_positional_argument(PositionalArgument("mode", "Operation mode"));
	parser.add_positional_argument(PositionalArgument("another", "another"));

	parser.add_argument(Argument("target", "-t", "--target", "", false, "Help for arg1"));
	parser.add_argument(Argument("port", "-p", "--port", "", false, "Help for arg2"));

	parser.add_argument(BooleanSwitchArgument("verbose", "-v", "--verbose", false, false, "Verbose mode. (default: false)"));

	parser.parse_args(argc, argv);
}


int main(int argc, char* argv[])
{
	ArgumentsParser parser;
	parseArgs(parser, argc, argv);

	//if (parser.arguments["verbose"].value == true) {
	//	std::cout << "Verbose = true";
	//}
	//else {
	//	std::cout << "Verbose = false";
	//}
}
