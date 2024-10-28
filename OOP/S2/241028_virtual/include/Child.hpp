#pragma once
#include "Base.hpp"

class Child : public Base {
public:
    Child(int iField, float fField, double dField);

    double getDField() const { return dField; }

    virtual void print() const override;

    ~Child();

private:
    double dField;
};
