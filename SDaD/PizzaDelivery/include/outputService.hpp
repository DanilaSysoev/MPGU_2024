#pragma once
#ifndef OUTPUTSERVICE_HPP
#define OUTPUTSERVICE_HPP

#include <vector>


template <typename T>
void printListOf(const std::vector<T>& list)
{
    for (int j = 0; j < list.size(); ++j)
        std::cout << j + 1 << ". " << list[j].toString() << '\n';
}

void printMessage(const std::string& message);

#endif