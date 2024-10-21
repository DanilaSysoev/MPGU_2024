#pragma once

class Calculator {
private:
    int value;

public:
    Calculator(int value);

    int getValue() const { return value; }

    Calculator operator+(const Calculator& other) const;
    Calculator operator-(const Calculator& other) const;
    Calculator operator*(const Calculator& other) const;
    Calculator operator/(const Calculator& other) const;
    Calculator operator%(const Calculator& other) const;
};
