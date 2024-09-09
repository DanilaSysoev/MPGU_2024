#pragma once
#ifndef PIZZAREPOSITORY_HPP
#define PIZZAREPOSITORY_HPP

#include<string>
#include<vector>

#include "entities.hpp"

void addPizza(std::vector<Pizza>& pizzaList);
void listOfPizza(const std::vector<Pizza>& pizzaList);
void removePizza(std::vector<Pizza>& pizzaList);

#endif
