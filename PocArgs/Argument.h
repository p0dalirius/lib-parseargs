#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <string>

class Argument
{
    public:
        std::string name;
        std::string shortoption;
        std::string longoption;
        std::string value;
        std::string defaultValue;
        bool required;
        std::string help;
    
    Argument();
    Argument(std::string name, std::string shortoption, std::string longoption, std::string defaultValue, bool required, std::string help);
};

#endif
