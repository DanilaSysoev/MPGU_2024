#pragma once
#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include "Store.hpp"


namespace ShopSystem
{
    class Terminal
    {
    public:
        Terminal(const Store& store);
        Terminal(const std::string& storeName);

        void PrintReport() const;
    private:
        Store _store;
    };
}


#endif
