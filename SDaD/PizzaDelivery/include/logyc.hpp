#include<string>
#include<vector>


struct Pizza
{
    std::string name;
};
struct Order
{
    std::string date;
    std::string address;
    std::vector<Pizza> pizza;
    bool delivered;

    std::string toString();
};

int readIntFromCin();
void printMainMenu();
void addOrder(std::vector<Pizza>& pizzaList, std::vector<Order>& orders);
void deliveryOrder(std::vector<Order>& orders);
void cancelOrder(std::vector<Order>& orders);
void addPizza(std::vector<Pizza>& pizzaList);
void listOfPizza(std::vector<Pizza>& pizzaList);
void removePizza(std::vector<Pizza>& pizzaList);
void allOrders(std::vector<Order>& orders);
void notDeliveredOrders(std::vector<Order>& orders);
