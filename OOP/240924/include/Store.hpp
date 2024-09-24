#pragma once
#ifndef STORE_HPP
#define STORE_HPP


#include <string>
#include <vector>
#include <cstdint>
#include "Goods.hpp"

namespace ShopSystem
{
    class Store
    {
    public:
        Store(const std::string& name);

        std::string GetName() const { return _name; }
        
        uint32_t GetGoodsCount()              const { return _goods.size(); }
        const Goods& GetGoods(uint32_t index) const { return _goods[index]; }
        
        void AddGoods(const Goods& goods);
        void RemoveGoods(uint32_t index);
        int32_t FindIndexById(int64_t id) const;

    private:
        std::string _name;
        std::vector<Goods> _goods;
    };
}


#endif