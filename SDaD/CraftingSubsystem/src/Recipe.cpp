#include "Recipe.hpp"

#include "ItemsCatalog.hpp"

uint32_t Crafting::Recipe::GetIngredientsCount() const {
    return _ingredients.size();
}

uint32_t Crafting::Recipe::GetResultsCount() const {
    return _results.size();
}

void Crafting::Recipe::AddIngredient(const Item& ingredient) {
    _ingredients.push_back(ingredient);
}

void Crafting::Recipe::AddResult(const Item& result) {
    _results.push_back(result);
}

void Crafting::Recipe::ApplyTo(ItemsCatalog& catalog)
{
    if(CanBeApplied(catalog)) {
        for(const auto& ingredient: _ingredients) {
            catalog.RemoveItem(ingredient.GetName());
        }
        for(const auto& result: _results) {
            catalog.AddItem(result);
        }
    }
}

uint32_t Crafting::Recipe::GetIngredientsCount(const std::string& name) const
{
    uint32_t count = 0;
    for(const auto& ingredient: _ingredients) {
        if(ingredient.GetName() == name) {
            count++;
        }
    }
    return count;
}

bool Crafting::Recipe::CanBeApplied(const ItemsCatalog& catalog) const {
    for(const auto& ingredient: _ingredients)
    {
        auto name = ingredient.GetName();
        if(catalog.GetItemsCount(name) < GetIngredientsCount(name))
            return false;
    }
    return true;
}
