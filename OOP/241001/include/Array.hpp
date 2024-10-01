#pragma once
#ifndef ARRAY_HPP

class Array
{
public:
    Array(int size);
    ~Array();
    int& operator[](int index);
    int operator[](int index) const;

    Array& operator=(const Array& other);

    void print() const;

private:
    int* data;
    int size;
};

#endif