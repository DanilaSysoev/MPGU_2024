#include "Item.hpp"

Crafting::Item Crafting::Item::Create(const std::string& name) {
    return { name };
}

Crafting::Item::Item(const std::string& name)
    : _name(name)
{}
