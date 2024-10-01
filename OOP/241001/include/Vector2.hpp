#pragma once
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>

class Vector2 {
public:
    Vector2();
    Vector2(float x, float y);

    float getX() const { return x; }
    float getY() const { return y; }

    void print() const;

    Vector2& operator=(const Vector2& other);
    Vector2& operator+=(const Vector2& ro);

    Vector2 operator+(const Vector2& ro) const;
    Vector2 operator-(const Vector2& ro) const;
    Vector2 operator*(float ro) const;
    Vector2 operator/(float ro) const;
    Vector2 operator-() const;
    Vector2 operator+() const;
    
    float dot(const Vector2& ro) const;
private:
    float x;
    float y;

    friend Vector2 operator*(float lo, const Vector2& ro);
    friend std::istream& operator>>(std::istream& in, Vector2& ro);
};

Vector2 operator*(float lo, const Vector2& ro);
std::ostream& operator<<(std::ostream& out, const Vector2& ro);
std::istream& operator>>(std::istream& in, Vector2& ro);

#endif
