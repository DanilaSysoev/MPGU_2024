#pragma once
#ifndef GOODS_HPP
#define GOODS_HPP


#include <string>
#include <cstdint>

namespace ShopSystem
{
    class Goods
    {
    public:
        Goods(int64_t id);

        int64_t GetId()        const { return _id; }
        std::string GetName()  const { return _name; }
        int64_t GetBuyPrice()  const { return _buyPrice; }
        int64_t GetSellPrice() const { return _sellPrice; }
        uint32_t GetCount()    const { return _count; }

        void SetName(const std::string& name) { _name = name; }
        void SetBuyPrice(int64_t buyPrice)    { _buyPrice = buyPrice; }
        void SetSellPrice(int64_t sellPrice)  { _sellPrice = sellPrice; }
        void SetCount(uint32_t count)         { _count = count; }

        void IncreaseCount(uint32_t value)    { _count += value; }
        void DecreaseCount(uint32_t value)    { _count -= value; }

    private:
        int64_t _id;
        std::string _name;
        int64_t _buyPrice;
        int64_t _sellPrice;
        uint32_t _count;
    };
}


#endif
