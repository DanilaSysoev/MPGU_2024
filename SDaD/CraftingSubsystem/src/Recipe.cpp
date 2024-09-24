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
    for(const auto& ingredient: _ingredients) {
        catalog.RemoveItem(ingredient.GetName());
    }
    for(const auto& result: _results) {
        catalog.AddItem(result);
    }
}

bool Crafting::Recipe::CanBeApplied(const ItemsCatalog& catalog) const {
    
}
