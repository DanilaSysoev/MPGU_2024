#include <limits>
#include <iostream>

#include "pizzaRepository.hpp"
#include "console_ui.hpp"
#include "outputService.hpp"

void addPizza(std::vector<Pizza>& pizzaList)
{
    printMessage("Enter pizza name:");
    std::string name;
    std::getchar();
    std::getline(std::cin, name);
    pizzaList.push_back({name});
}

void listOfPizza(const std::vector<Pizza>& pizzaList)
{
    printMessage("List of pizza:");
    printListOf(pizzaList);
}

void tryRemovePizza(std::vector<Pizza>& pizzaList, int pizzaNumber)
{
    if (pizzaNumber > 0 && pizzaNumber <= pizzaList.size())
        pizzaList.erase(pizzaList.begin() + pizzaNumber);
}

void removePizza(std::vector<Pizza>& pizzaList)
{
    printMessage("Select pizza:");
    printListOf(pizzaList);

    int pizzaNumber = readIntFromCin();
    tryRemovePizza(pizzaList, pizzaNumber);
}
