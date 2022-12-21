#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <iostream>
#include <string>
#include <list>
#include <map>

#include "Argument.h"
#include "BooleanSwitchArgument.h"
#include "PositionalArgument.h"

class ArgumentsParser
{
    public:
        void parse_args(int argc, char * argv[]);
        void add_argument(Argument arg);
        void add_positional_argument(Argument arg);
        void add_subparser(std::string name);
        void help(int argc, char* argv[]);

        std::map<std::string, Argument> arguments;

    private:
        std::list<Argument> positionalArguments;

        std::list<Argument> allArguments;
        std::list<Argument> mandatoryArguments;
        std::list<Argument> optionalArguments;
};

#endif

