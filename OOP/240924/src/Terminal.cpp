#include <iostream>
#include "Terminal.hpp"

ShopSystem::Terminal::Terminal(const std::string& storeName)
    : _store(storeName)
{}

ShopSystem::Terminal::Terminal(const Store& store)
    : _store(store)
{}

void ShopSystem::Terminal::PrintReport() const {
    std::cout << "Report for " << _store.GetName() << ":" << std::endl;
    std::cout << "Goods [" << _store.GetGoodsCount() << "]:" << std::endl;
    for (uint32_t i = 0; i < _store.GetGoodsCount(); ++i) {
        auto goods = _store.GetGoods(i);
        std::cout << "Good #" << i << ": "
                  << goods.GetName() << std::endl
                  << "   Buy price: " << goods.GetBuyPrice() << std::endl
                  << "   Sell price: " << goods.GetSellPrice() << std::endl
                  << "   Count: " << goods.GetCount() << std::endl;
    }
}
