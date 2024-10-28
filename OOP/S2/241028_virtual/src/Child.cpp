#include <iostream>
#include "Child.hpp"

Child::Child(int iField, float fField, double dField)
    : Base(iField, fField), dField(dField)
{}

void Child::print() const {
    std::cout << "Child:\n" << " iField: " << getIField()
                            << " fField: " << getFField()
                            << " dField: " << getDField();
}

Child::~Child() {
    std::cout << "Child destructor\n";
}
