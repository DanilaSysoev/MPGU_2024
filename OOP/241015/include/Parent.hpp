#pragma once
#include <iostream>

class Parent {
public:
    Parent(int iField, float fField);

    int getIField() const { return iField; }
    float getFField() const { return fField; }

    ~Parent();

private:
    int iField;
    float fField;
};

std::ostream& operator<<(std::ostream& os, const Parent& parent);
