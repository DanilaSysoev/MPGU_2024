#pragma once

class Base {
public:
    Base(int iField, float fField);

    int getIField() const { return iField; }
    float getFField() const { return fField; }

    virtual void print() const;

    virtual ~Base();

private:
    int iField;
    float fField;
};
