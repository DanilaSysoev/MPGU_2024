#include <stdexcept>
#include <vector>

#include "ItemsCatalog.hpp"
#include "Item.hpp"


void Crafting::ItemsCatalog::AddItem(const Item& item) {
    _items.push_back(item);
}

void Crafting::ItemsCatalog::RemoveItem(const std::string& name) {
    auto index = GetIndexByName(name);
    if(index < 0)
        throw std::runtime_error("Item not found");
    
    _items.erase(_items.begin() + index);
}

const Crafting::Item&
Crafting::ItemsCatalog::GetItem(const std::string& name) const {
    auto index = GetIndexByName(name);
    if (index >= 0)
        return _items[index];

    throw std::runtime_error("Item not found");
}

int32_t Crafting::ItemsCatalog::GetIndexByName(const std::string& name) const {
    for (uint32_t i = 0; i < _items.size(); ++i) {
        if(_items[i].GetName() == name)
            return i;
    }
    return -1;
}

uint32_t Crafting::ItemsCatalog::GetItemsCount(const std::string& name) const {
    uint32_t count = 0;
    for (uint32_t i = 0; i < _items.size(); ++i) {
        if(_items[i].GetName() == name)
            ++count;
    }
    return count;
}

Crafting::ItemsCatalog& Crafting::ItemsCatalog::Get() {
    if(_created)
        return _instance;

    throw std::runtime_error("ItemsCatalog not created");
}

void Crafting::ItemsCatalog::Create() {
    _instance = ItemsCatalog();
    _created = true;
}

void Crafting::ItemsCatalog::Clear() {
    _created = false;
}

Crafting::ItemsCatalog Crafting::ItemsCatalog::_instance;
bool Crafting::ItemsCatalog::_created = false;
