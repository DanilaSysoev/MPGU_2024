#pragma once
#include <iostream>

class SecondParent {
public:
    SecondParent(int iField);

    int getIField() const { return iField; }

    ~SecondParent();

private:
    int iField;
};

std::ostream& operator<<(std::ostream& os, const SecondParent& secondParent);