#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "console_ui.hpp"
#include "inputService.hpp"
#include "outputService.hpp"
#include "pizzaRepository.hpp"
#include "orderRepository.hpp"

using namespace std;

int main()
{
    vector<Pizza> pizzaList{};
    vector<Order> orders{};

    bool is_over = false;

    while (!is_over)
    {
        printMainMenu();

        int command = getInt();

        switch (command)
        {
        case 1:
            addOrder(pizzaList, orders);
            break;
        case 2:
            deliveryOrder(orders);
            break;
        case 3:
            cancelOrder(orders);
            break;
        case 4:
            addPizza(pizzaList);
            break;
        case 5:
            removePizza(pizzaList);
            break;
        case 6:
            listOfPizza(pizzaList);
            break;
        case 7:
            allOrders(orders);
            break;
        case 8:
            notDeliveredOrders(orders);
            break;
        case 9:
            is_over = true;
            break;
        default:
            printMessage("Unknown command. Try again");
            break;
        }
    }

    return 0;
}
