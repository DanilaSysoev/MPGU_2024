#pragma once

#include <iostream>
#include "Parent.hpp"

class Child : public Parent {
public:
    Child(int iField, float fField, double dField);
    double getDField() const { return dField; }

    ~Child();
private:
    double dField;
};

std::ostream& operator<<(std::ostream& os, const Child& parent);
