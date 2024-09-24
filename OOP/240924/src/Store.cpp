#include <iostream>
#include "Store.hpp"

ShopSystem::Store::Store(const std::string& name)
    : _name(name)
{
    std::cout << "Store: " << _name << std::endl;
}


void ShopSystem::Store::AddGoods(const Goods& goods) {
    if(FindIndexById(goods.GetId()) < 0)
        _goods.push_back(goods);
}

void ShopSystem::Store::RemoveGoods(uint32_t index) {
    _goods.erase(_goods.begin() + index);
}

int32_t ShopSystem::Store::FindIndexById(int64_t id) const {
    for(uint32_t i = 0; i < _goods.size(); ++i) {
        if(_goods[i].GetId() == id)
            return i;
    }
    return -1;
}
