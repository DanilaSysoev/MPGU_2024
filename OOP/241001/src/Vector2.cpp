#include <iostream>
#include "Vector2.hpp"

Vector2::Vector2()
    : x(0), y(0)
{}

Vector2::Vector2(float x, float y)
    : x(x), y(y)
{}

void Vector2::print() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

Vector2 Vector2::operator+(const Vector2& ro) const {
    return Vector2(x + ro.x, y + ro.y);
}

Vector2 Vector2::operator-(const Vector2& ro) const {
    return Vector2(x - ro.x, y - ro.y);
}

Vector2 Vector2::operator*(float ro) const {
    return Vector2(x * ro, y * ro);
}
Vector2 Vector2::operator/(float ro) const {
    return Vector2(x / ro, y / ro);
}
Vector2 Vector2::operator-() const {
    return Vector2(-x, -y);
}
Vector2 Vector2::operator+() const {
    return Vector2(x, y);
}

Vector2 operator*(float lo, const Vector2& ro) {
    return Vector2(lo * ro.x, lo * ro.y);
}

Vector2& Vector2::operator=(const Vector2& other) {
    if(this == &other)
        return *this;

    x = other.x;
    y = other.y;
    return *this;
}
Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector2& ro) {
    out << "(" << ro.getX() << ", " << ro.getY() << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector2& ro) {
    in >> ro.x >> ro.y;
    return in;
}
