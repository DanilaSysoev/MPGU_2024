#pragma once
#include <iostream>

#include "Parent.hpp"
#include "SecondParent.hpp"

class DoubleChild : public Parent,
                    public SecondParent
{
public:
    DoubleChild(int pIField, int spIField, float fField, double dField);
    ~DoubleChild();

    double getDField() const { return dField; }

private:
    double dField;
};

std::ostream& operator<<(std::ostream& os, const DoubleChild& dc);
