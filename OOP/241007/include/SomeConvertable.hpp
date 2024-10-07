#pragma once

class SomeConvertable {
private:
    double dValue;
    int iValue;

public:
    SomeConvertable(double dValue, int iValue)
        : dValue(dValue), iValue(iValue)
    {}

    explicit operator double() const {
        return dValue;
    }

    explicit operator int() const {
        return iValue;
    }
};