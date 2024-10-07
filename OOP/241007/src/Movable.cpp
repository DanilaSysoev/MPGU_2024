#include <iostream>
#include "Movable.hpp"

Movable::Movable(int size)
    : size(size)
{
    std::cout << "Movable Movable::Movable(int size)" << std::endl;

    this->size = size;
    data = new int[size];
}
Movable::Movable(const Movable& other)
    : size(other.size)
{
    std::cout << "Movable Movable::Movable(const Movable& other)" << std::endl;

    data = new int[size];
    for (int i = 0; i < size; ++i)
        data[i] = other.data[i];
}
Movable::Movable(Movable&& other)
{
    std::cout << "Movable& Movable::Movable(Movable&& other)" << std::endl;

    data = other.data;
    size = other.size;
    other.data = nullptr;
}

Movable::~Movable() {
    std::cout << "Movable::~Movable()" << std::endl;

    if(data != nullptr)
        delete[] data;
}

Movable& Movable::operator=(const Movable& other) {
    if (this == &other)
        return *this;

    std::cout << "Movable& Movable::operator=(const Movable& other)" << std::endl;

    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; ++i)
        data[i] = other.data[i];

    return *this;
}
Movable& Movable::operator=(Movable&& other) {
    if (this == &other)
        return *this;

    std::cout << "Movable& Movable::operator=(Movable&& other)" << std::endl;

    delete[] data;
    data = other.data;
    size = other.size;
    other.data = nullptr;

    return *this;
}
