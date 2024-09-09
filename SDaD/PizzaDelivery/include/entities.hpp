#pragma once
#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include<string>
#include<vector>

struct Pizza
{
    std::string name;

    std::string toString() const;
};
struct Order
{
    std::string date;
    std::string address;
    std::vector<Pizza> pizza;
    bool delivered;

    std::string toString() const;
};

#endif
