#include "DoubleChild.hpp"

DoubleChild::DoubleChild(
    int pIField, int spIField, float fField, double dField
) : Parent(pIField, fField), SecondParent(spIField), dField(dField)
{
    std::cout << "DoubleChild constructor" << std::endl;
}

DoubleChild::~DoubleChild() {
    std::cout << "DoubleChild destructor" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const DoubleChild& dc) {
    os << "DoubleChild: " << dc.Parent::getIField() << " "
                          << dc.getFField() << " "
                          << dc.SecondParent::getIField() << " "
                          << dc.getDField();
    return os;
}
