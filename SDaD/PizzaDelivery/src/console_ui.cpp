#include <limits>
#include <iostream>

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