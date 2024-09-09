#include "entities.hpp"


std::string Order::toString() const
{
    return date + " # " + address + " [" + (delivered ? "+" : "-") + "]";
}
std::string Pizza::toString() const
{
    return name;
}
