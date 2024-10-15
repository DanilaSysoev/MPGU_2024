#include "Child.hpp"

Child::Child(int iField, float fField, double dField)
    : Parent(iField, fField), dField(dField)
{
    std::cout << "Child constructor" << std::endl;
}

Child::~Child() {
    std::cout << "Child destructor" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Child& child) {
    os << "Child: " << child.getIField() << " " << child.getFField() << " " << child.getDField();
    return os;
}
