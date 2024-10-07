#include <iostream>

#include "NumberService.hpp"

NumberService::NumberService(int number)
    : number(number)
{}

void NumberService::add(int number) {
    this->number += number;
}
void NumberService::sub(int number) {
    this->number -= number;
}
void NumberService::mul(int number) {
    this->number *= number;
}
void NumberService::div(int number) {
    this->number /= number;
}

void NumberService::print() const {
    std::cout << "NumberService: " << this->number << std::endl;
}
