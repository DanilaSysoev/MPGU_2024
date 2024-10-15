#pragma once
#include "TopLevel.hpp"

class SecondLevelOne : public virtual TopLevel {
public:
    SecondLevelOne(int iField, float fField);

    float getFField() const { return fField; }

private:
    float fField;
};
