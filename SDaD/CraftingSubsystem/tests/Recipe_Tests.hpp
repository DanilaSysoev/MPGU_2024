#include <gtest/gtest.h>
#include <stdexcept>

#include "ItemsCatalog.hpp"
#include "Recipe.hpp"
#include "Item.hpp"


TEST(RecipeTests, Create_EmptyRecipe_HasNoIngredients) {
    Crafting::Recipe recipe;
    ASSERT_EQ(recipe.GetIngredientsCount(), 0);
}

TEST(RecipeTests, Create_EmptyRecipe_HasNoResults) {
    Crafting::Recipe recipe;
    ASSERT_EQ(recipe.GetResultsCount(), 0);
}

TEST(RecipeTests, AddIngredient_AddToEmptyRecipe_IngredientsCountEqualsOne) {
    Crafting::Recipe recipe;
    Crafting::Item ingredient = Crafting::Item::Create("Apple");
    recipe.AddIngredient(ingredient);
    ASSERT_EQ(recipe.GetIngredientsCount(), 1);
}

TEST(RecipeTests, AddResult_AddToEmptyRecipe_ResultscountCountEqualsOne) {
    Crafting::Recipe recipe;
    Crafting::Item result = Crafting::Item::Create("Apple");
    recipe.AddResult(result);
    ASSERT_EQ(recipe.GetResultsCount(), 1);
}

TEST(RecipeTests, Name_SetSomeName_GetReturnsSameName) {
    Crafting::Recipe recipe;
    recipe.SetName("Banana pancake");
    ASSERT_EQ(recipe.GetName(), "Banana pancake");
}

TEST(RecipeTests, Apply_ApplyEmptyRecipe_CatalogSizeNotChanged) {
    Crafting::ItemsCatalog::Clear();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();

    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Apple"));

    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));

    catalog.AddItem(Crafting::Item::Create("Flour"));

    catalog.AddItem(Crafting::Item::Create("Water"));

    Crafting::Recipe recipe;
    recipe.ApplyTo(catalog);
    ASSERT_EQ(catalog.GetSize(), 10);
}

TEST(RecipeTests, Apply_ApplyEmptyRecipe_CatalogListNotChanged) {
    Crafting::ItemsCatalog::Clear();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();

    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Flour"));

    Crafting::Recipe recipe;
    recipe.ApplyTo(catalog);
    ASSERT_EQ(catalog.GetItemsCount("Apple"), 1);
    ASSERT_EQ(catalog.GetItemsCount("Cherry"), 2);
    ASSERT_EQ(catalog.GetItemsCount("Flour"), 1);
}

TEST(RecipeTests, Apply_ApplyRecipeWithIngrWithoutRes_CatalogListChangedCorrectly) {
    Crafting::ItemsCatalog::Clear();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();

    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Flour"));

    Crafting::Recipe recipe;
    recipe.AddIngredient(Crafting::Item::Create("Apple"));
    recipe.ApplyTo(catalog);
    ASSERT_EQ(catalog.GetItemsCount("Apple"), 0);
    ASSERT_EQ(catalog.GetItemsCount("Cherry"), 2);
    ASSERT_EQ(catalog.GetItemsCount("Flour"), 1);
}

TEST(RecipeTests, Apply_ApplyRecipeWithoutIngrWithRes_CatalogListChangedCorrectly) {
    Crafting::ItemsCatalog::Clear();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();

    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Flour"));

    Crafting::Recipe recipe;
    recipe.AddResult(Crafting::Item::Create("Orange"));
    recipe.ApplyTo(catalog);
    ASSERT_EQ(catalog.GetItemsCount("Apple"), 1);
    ASSERT_EQ(catalog.GetItemsCount("Cherry"), 2);
    ASSERT_EQ(catalog.GetItemsCount("Flour"), 1);
    ASSERT_EQ(catalog.GetItemsCount("Orange"), 1);
}


TEST(RecipeTests, Apply_ApplyRecipeWithIngrWithoutRes_CatalogSizeChangedCorrectly) {
    Crafting::ItemsCatalog::Clear();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();

    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Flour"));

    Crafting::Recipe recipe;
    recipe.AddIngredient(Crafting::Item::Create("Apple"));
    recipe.ApplyTo(catalog);
    ASSERT_EQ(catalog.GetSize(), 3);
}

TEST(RecipeTests, Apply_ApplyRecipeWithoutIngrWithRes_CatalogSizeChangedCorrectly) {
    Crafting::ItemsCatalog::Clear();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();

    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Flour"));

    Crafting::Recipe recipe;
    recipe.AddResult(Crafting::Item::Create("Orange"));
    recipe.ApplyTo(catalog);
    ASSERT_EQ(catalog.GetSize(), 5);
}

TEST(RecipeTests, Apply_ApplyRecipeToUnderstuffedCatalog_CatalogSizeNotChanged) {
    Crafting::ItemsCatalog::Clear();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();

    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Flour"));

    Crafting::Recipe recipe;
    recipe.AddIngredient(Crafting::Item::Create("Water"));
    recipe.AddResult(Crafting::Item::Create("Orange"));
    recipe.ApplyTo(catalog);
    ASSERT_EQ(catalog.GetSize(), 4);
}

TEST(RecipeTests, Apply_ApplyRecipeToUnderstuffedCatalog_CatalogListNotChanged) {
    Crafting::ItemsCatalog::Clear();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();

    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Cherry"));
    catalog.AddItem(Crafting::Item::Create("Flour"));

    Crafting::Recipe recipe;
    recipe.AddIngredient(Crafting::Item::Create("Water"));
    recipe.AddResult(Crafting::Item::Create("Orange"));
    recipe.ApplyTo(catalog);
    ASSERT_EQ(catalog.GetItemsCount("Apple"), 1);
    ASSERT_EQ(catalog.GetItemsCount("Cherry"), 2);
    ASSERT_EQ(catalog.GetItemsCount("Flour"), 1);
}
