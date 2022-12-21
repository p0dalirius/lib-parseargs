#ifndef BOOLEANSWITCHARGUMENT_H
#define BOOLEANSWITCHARGUMENT_H

#include "Argument.h"
#include <string>


class BooleanSwitchArgument : public Argument
{
    public:
        std::string name;
        std::string shortoption;
        std::string longoption;
        bool value;
        bool defaultValue;
        bool required;
        std::string help;

    BooleanSwitchArgument();
    BooleanSwitchArgument(std::string name, std::string shortoption, std::string longoption, bool defaultValue, bool required, std::string help);
};

#endif