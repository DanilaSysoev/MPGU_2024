#include <limits>
#include <iostream>
#include <string>

int getInt()
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

std::string getLine()
{
    std::string data;
    std::getline(std::cin, data);
    if(data.empty())
        std::getline(std::cin, data);
    return data;
}