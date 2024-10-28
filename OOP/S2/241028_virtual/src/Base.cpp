#include <iostream>
#include "Base.hpp"

Base::Base(int iField, float fField)
    : iField(iField), fField(fField)
{}

void Base::print() const {
    std::cout << "Base:\n" << " iField: " << iField
                           << " fField: " << fField;
}

Base::~Base() {
    std::cout << "Base destructor\n";
}