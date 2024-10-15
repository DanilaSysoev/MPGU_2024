#pragma once
#include "TopLevel.hpp"

class SecondLevelTwo : public virtual TopLevel {
public:
    SecondLevelTwo(int iField, float dField);

    float getDField() const { return dField; }

private:
    double dField;
};
