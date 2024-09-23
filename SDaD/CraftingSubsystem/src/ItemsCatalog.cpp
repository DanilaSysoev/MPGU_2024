#include <stdexcept>
#include <vector>

#include "ItemsCatalog.hpp"
#include "Item.hpp"


void Crafting::ItemsCatalog::AddItem(const Item& item) {
    auto it = GetByName(item.GetName());
    if(it)
        throw std::runtime_error("Item already exists");

    _items.push_back(item);
}

const Crafting::Item&
Crafting::ItemsCatalog::GetItem(const std::string& name) const {
    auto item = GetByName(name);
    if (item)
        return *item;

    throw std::runtime_error("Item not found");
}

std::optional<const Crafting::Item>
Crafting::ItemsCatalog::GetByName(const std::string& name) const {
    for(const auto& item : _items) {
        if(item.GetName() == name)
            return std::optional<const Crafting::Item>{ item };
    }
    return std::nullopt;
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
