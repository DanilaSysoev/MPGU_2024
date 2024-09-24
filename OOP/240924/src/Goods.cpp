#include <iostream>
#include "Goods.hpp"

ShopSystem::Goods::Goods(int64_t id)
    : _id(id)
{
    std::cout << "Goods: " << _id << std::endl;
}
