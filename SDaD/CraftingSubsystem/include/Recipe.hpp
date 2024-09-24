#include <cstdint>
#include <vector>
#include <string>

#include "Item.hpp"

#pragma once

namespace Crafting
{
    class ItemsCatalog;

    class Recipe
    {
    public:
        uint32_t GetIngredientsCount() const;
        uint32_t GetResultsCount() const;
        void AddIngredient(const Item& ingredient);
        void AddResult(const Item& result);

        void SetName(const std::string& name) { _name = name; }
        std::string GetName() const { return _name; }

        void ApplyTo(ItemsCatalog& catalog);
        bool CanBeApplied(const ItemsCatalog& catalog) const;

    private:
        std::vector<Item> _ingredients;
        std::vector<Item> _results;
        std::string _name;
    };
}