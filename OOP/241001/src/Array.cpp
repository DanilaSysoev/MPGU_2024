#include <iostream>
#include "Array.hpp"

Array::Array(int size) {
    this->size = size;
    this->data = new int[size];
}
Array::~Array() {
    delete[] data;
}
int& Array::operator[](int index) {
    return data[index];
}
int Array::operator[](int index) const {
    return data[index];
}
Array& Array::operator=(const Array& other) {    
    if(this == &other)
        return *this;
    
    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    
    return *this;
}

void Array::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}