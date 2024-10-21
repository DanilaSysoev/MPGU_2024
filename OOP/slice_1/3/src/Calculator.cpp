#include "Calculator.hpp"

Calculator::Calculator(int value)
    : value(value)
{}

Calculator Calculator::operator+(const Calculator& other) const {
    return Calculator(value + other.value);
}
Calculator Calculator::operator-(const Calculator& other) const {
    return Calculator(value - other.value);
}
Calculator Calculator::operator*(const Calculator& other) const {
    return Calculator(value * other.value);
}
Calculator Calculator::operator/(const Calculator& other) const {
    return Calculator(value / other.value);
}
Calculator Calculator::operator%(const Calculator& other) const {
    return Calculator(value % other.value);
}
