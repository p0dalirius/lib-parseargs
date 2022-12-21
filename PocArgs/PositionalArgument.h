#ifndef POSITIONALARGUMENT_H
#define POSITIONALARGUMENT_H

#include "Argument.h"
#include <string>

class PositionalArgument : public Argument
{
    public:
        std::string name;
        std::string help;

    PositionalArgument();
    PositionalArgument(std::string name, std::string help);
};

#endif
