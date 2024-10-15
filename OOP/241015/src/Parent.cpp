#include <iostream>
#include "Parent.hpp"

Parent::Parent(int iField, float fField)
    : iField(iField), fField(fField)
{
    std::cout << "Parent constructor" << std::endl;
}

Parent::~Parent() {
    std::cout << "Parent destructor" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Parent& parent) {
    os << "Parent: " << parent.getIField() << " " << parent.getFField();
    return os;
}
