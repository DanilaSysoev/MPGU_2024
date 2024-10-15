#include "SecondParent.hpp"

SecondParent::SecondParent(int iField)
    : iField(iField)
{
    std::cout << "SecondParent constructor" << std::endl;
}

SecondParent::~SecondParent() {
    std::cout << "SecondParent destructor" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SecondParent& sp) {
    os << "SecondParent: " << sp.getIField();
    return os;
}
