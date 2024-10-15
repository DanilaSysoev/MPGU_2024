#include <iostream>
#include "TopLevel.hpp"

TopLevel::TopLevel(int iField)
    : iField(iField)
{
    std::cout << "Constructing TopLevel with iField: " << iField << std::endl;
}
