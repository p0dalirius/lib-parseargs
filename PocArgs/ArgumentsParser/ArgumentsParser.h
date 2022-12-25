#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <iostream>
#include <string>
#include <list>
#include <map>

#include "Argument.h"
#include "ArgumentType.h"


class ArgumentsParser
{
    public:
        std::map<std::string, std::string> arguments;

        /* Add arguments */
        void add_positional_string_argument(const std::string& name, const std::string& help);
        void add_boolean_switch_argument(const std::string& name, const std::string& shortoption, const std::string& longoption, bool defaultValue, bool required, const std::string& help);
        void add_string_argument(const std::string& name, const std::string& shortoption, const std::string& longoption, const std::string& defaultValue, bool required, const std::string& help);
        void add_int_argument(const std::string& name, const std::string& shortoption, const std::string& longoption, const std::string& defaultValue, bool required, const std::string& help);
        /* Core methods */
        int parse_args(int argc, char* argv[]);
        void add_subparser(std::string name);
        void help(int argc, char* argv[]);

    private:
        std::list<Argument> positionalArguments;
        std::list<Argument> allArguments;
        std::list<Argument> mandatoryArguments;
        std::list<Argument> optionalArguments;
};

#endif

