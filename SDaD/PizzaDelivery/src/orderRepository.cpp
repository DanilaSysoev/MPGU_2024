#include <vector>
#include <iostream>

#include "inputService.hpp"
#include "console_ui.hpp"
#include "outputService.hpp"
#include "entities.hpp"

void addPizzaToOrder(const std::vector<Pizza>& pizzaList, Order& order)
{
    while(true)
    {
        printMessage("Select pizza:");
        printListOf(pizzaList);

        int pizzaNumber = getInt();

        if (pizzaNumber > 0 && pizzaNumber <= pizzaList.size()) {
            order.pizza.push_back(pizzaList[pizzaNumber - 1]);
            break;
        }
        else
            printMessage("Invalid number of pizza. Try again.");
    }
}

Order createOrderInfo()
{
    Order order{};
    
    printMessage("Enter order date:");
    order.date = getLine();
    printMessage("Enter order address:");
    order.address = getLine();
    printMessage("How many pizza?");

    return order;
}

void addOrder(const std::vector<Pizza>& pizzaList, std::vector<Order>& orders)
{
    Order order = createOrderInfo();
    int numberOfPizza = getInt();
    if (numberOfPizza > 0)
    {
        for (int i = 0; i < numberOfPizza; ++i)
            addPizzaToOrder(pizzaList, order);

        orders.push_back(order);
    }
}

std::vector<Order> getNotDeliveredOrders(const std::vector<Order>& orders)
{
    std::vector<Order> notDeliveredOrders;

    for (int i = 0; i < orders.size(); ++i)
    {
        if (!orders[i].delivered)
            notDeliveredOrders.push_back(orders[i]);
    }

    return notDeliveredOrders;
}

void printNotDeliveredOrders(const std::vector<Order>& orders)
{
    printListOf(getNotDeliveredOrders(orders));
}

int getNotDeliveredOrderNumber(const std::vector<Order>& orders)
{
    return getNotDeliveredOrders(orders).size();
}
void deliveryNotDeliveredOrderWithNumber(
    std::vector<Order>& orders, int orderNumber
)
{
    getNotDeliveredOrders(orders)[orderNumber - 1].delivered = true;
}

void deliveryOrder(std::vector<Order>& orders)
{
    printMessage("Select order:");
    printNotDeliveredOrders(orders);

    int orderNumber = getInt();
    if (orderNumber > 0 && orderNumber <= getNotDeliveredOrderNumber(orders))
        deliveryNotDeliveredOrderWithNumber(orders, orderNumber);
}

void printOrders(const std::vector<Order>& orders)
{
    printListOf(orders);
}

void tryApplyCancelation(std::vector<Order>& orders, int orderNumber)
{
    if (orderNumber > 0 && orderNumber <= orders.size())
    {
        if (orders[orderNumber - 1].delivered)
            printMessage("Order delivered");
        else
            orders.erase(orders.begin() + orderNumber - 1);
    }
}

void cancelOrder(std::vector<Order>& orders)
{
    printMessage("Select order:");
    printOrders(orders);

    int orderNumber = getInt();
    tryApplyCancelation(orders, orderNumber);
}

void allOrders(const std::vector<Order>& orders)
{
    printMessage("List of orders (all):");
    printOrders(orders);
}

void notDeliveredOrders(const std::vector<Order>& orders)
{
    printMessage("List of orders (not delivered):");
    printNotDeliveredOrders(orders);
}