#include <limits>
#include <iostream>

#include "logyc.hpp"

std::string Order::toString()
{
    return date + " # " + address + " [" + (delivered ? "+" : "-") + "]";
}

int readIntFromCin()
{
    int command = 0;
    std::cin >> command;
    if (!std::cin)
    {
        command = 0;
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        std::cin.clear();
    }
    return command;
}

void printMainMenu()
{
    std::cout << "Select oeration:" << std::endl;
    std::cout << "1. Add order" << std::endl;
    std::cout << "2. Delivery order" << std::endl;
    std::cout << "3. Cancel order" << std::endl;
    std::cout << "4. Add pizza" << std::endl;
    std::cout << "5. Remove pizza" << std::endl;
    std::cout << "6. List of pizza" << std::endl;
    std::cout << "7. List of orders (all)" << std::endl;
    std::cout << "8. List of orders (not delivered)" << std::endl;
    std::cout << "9. Quit" << std::endl;
}

void addOrder(std::vector<Pizza>& pizzaList, std::vector<Order>& orders)
{
    Order order{};
    std::cout << "Enter order date:\n";
    std::getchar();
    std::getline(std::cin, order.date);
    std::cout << "Enter order address:\n";
    std::getline(std::cin, order.address);
    std::cout << "How many pizza?\n";
    int numberOfPizza = readIntFromCin();
    if (numberOfPizza > 0)
    {
        for (int i = 0; i < numberOfPizza; ++i)
        {
            std::cout << "Select pizza number " << i + 1 << ":\n";
            for (int j = 0; j < pizzaList.size(); ++j)
                std::cout << j + 1 << ". " << pizzaList[j].name << '\n';

            int p = readIntFromCin();

            if (p > 0 && p <= pizzaList.size())
                order.pizza.push_back(pizzaList[p - 1]);
            else
                --i;
        }

        orders.push_back(order);
    }
}

void deliveryOrder(std::vector<Order>& orders)
{
    std::cout << "Select order:\n";
    int j = 1;
    for (int i = 0; i < orders.size(); ++i)
    {
        if (!orders[i].delivered)
            std::cout << j++ << ". " << orders[i].toString() << std::endl;
    }

    int o = readIntFromCin();
    if (o > 0 && o <= j)
    {
        for (int i = 0, k = 1; i < orders.size(); ++i)
        {
            if (!orders[i].delivered)
            {
                if (k == o)
                    orders[i].delivered = true;
                ++k;
            }
        }
    }
}

void cancelOrder(std::vector<Order>& orders)
{
    std::cout << "Select order:\n";
    for (int i = 0; i < orders.size(); ++i)
        std::cout << i + 1 << ". " << orders[i].toString() << std::endl;

    int o = readIntFromCin();

    if (o > 0 && o <= orders.size())
    {
        if (orders[o - 1].delivered)
            std::cout << "Order delivered\n";
        else
            orders.erase(orders.begin() + o - 1);
    }
}

void addPizza(std::vector<Pizza>& pizzaList)
{
    std::cout << "Enter pizza name:\n";
    std::string name;
    std::getchar();
    std::getline(std::cin, name);
    pizzaList.push_back({name});
}

void listOfPizza(std::vector<Pizza>& pizzaList)
{
    std::cout << "List of pizza:\n";
    for (int i = 0; i < pizzaList.size(); ++i)
        std::cout << i + 1 << ". " << pizzaList[i].name << std::endl;
}

void removePizza(std::vector<Pizza>& pizzaList)
{
    std::cout << "Select pizza:\n";
    for (int i = 0; i < pizzaList.size(); ++i)
        std::cout << i + 1 << ". " << pizzaList[i].name << std::endl;

    int o = readIntFromCin();
    if (o > 0 && o <= pizzaList.size())
        pizzaList.erase(pizzaList.begin() + o);
}

void allOrders(std::vector<Order>& orders)
{
    std::cout << "List of orders (all):\n";
    for (int i = 0; i < orders.size(); ++i)
        std::cout << i + 1 << ". " << orders[i].toString() << std::endl;
}

void notDeliveredOrders(std::vector<Order>& orders)
{
    std::cout << "List of orders (not delivered):\n";
    for (int i = 0, j = 1; i < orders.size(); ++i)
    {
        if (!orders[i].delivered)
            std::cout << j++ << ". " << orders[i].toString() << std::endl;
    }
}