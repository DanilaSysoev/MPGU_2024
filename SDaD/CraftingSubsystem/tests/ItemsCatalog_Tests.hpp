#include <gtest/gtest.h>
#include <stdexcept>

#include "ItemsCatalog.hpp"
#include "Item.hpp"

void MySetUp()
{

}
void MyTearDown()
{
    Crafting::ItemsCatalog::Clear();
}

TEST(ItemsCatalogTests, AddItem_AddSomeItem_CatalogSizeIncreaseByOne) {
    MySetUp();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();
    auto catalogSize = catalog.GetSize();
    auto item = Crafting::Item::Create("Item Name");
    catalog.AddItem(item);

    ASSERT_EQ(catalogSize + 1, catalog.GetSize());
    MyTearDown();
}

TEST(ItemsCatalogTests, Create_CreateCatalog_CatalogSizeEqualsZero) {
    MySetUp();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();

    ASSERT_EQ(0, catalog.GetSize());
    MyTearDown();
}

TEST(ItemsCatalogTests, Get_GetWithouCreating_TrowsError) {
    MySetUp();
    ASSERT_THROW(Crafting::ItemsCatalog::Get(), std::runtime_error);
    MyTearDown();
}

TEST(ItemsCatalogTests, AddItem_AddSomeItemThenGet_NameReturnedItemIsEqualsCreatedItem) {
    MySetUp();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();
    auto item = Crafting::Item::Create("Item Name");
    catalog.AddItem(item);
    ASSERT_EQ(catalog.GetItem("Item Name").GetName(), item.GetName());
    MyTearDown();
}

TEST(ItemsCatalogTests, AddItem_GetNonExistentItem_ThrowsError) {
    MySetUp();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();
    ASSERT_THROW(catalog.GetItem("Item Name"), std::runtime_error);
    MyTearDown();
}

TEST(ItemsCatalogTests, AddItem_AddDuplicateItem_SizeIncreased) {
    MySetUp();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();
    auto item = Crafting::Item::Create("Item Name");
    catalog.AddItem(item);
    auto size = catalog.GetSize();
    catalog.AddItem(item);
    ASSERT_EQ(size + 1, catalog.GetSize());
    MyTearDown();
}

TEST(ItemsCatalogTests, GetItemsCount_GetNonExistentItem_ReturnsZero) {
    MySetUp();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();
    auto item = Crafting::Item::Create("Item Name");
    catalog.AddItem(item);
    ASSERT_EQ(catalog.GetItemsCount("Apple"), 0);
    MyTearDown();
}

TEST(ItemsCatalogTests, GetItemsCount_GetExistingOneItem_ReturnsOne) {
    MySetUp();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();
    auto item = Crafting::Item::Create("Item Name");
    catalog.AddItem(item);
    ASSERT_EQ(catalog.GetItemsCount("Item Name"), 1);
    MyTearDown();
}

TEST(ItemsCatalogTests, GetItemsCount_GetExistingThreeItem_ReturnsThree) {
    MySetUp();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();
    auto item = Crafting::Item::Create("Item Name");
    catalog.AddItem(item);
    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Apple"));
    ASSERT_EQ(catalog.GetItemsCount("Apple"), 3);
    MyTearDown();
}

TEST(ItemsCatalogTests, Remove_RemoveExistingItem_CountDecrease) {
    MySetUp();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();
    auto item = Crafting::Item::Create("Item Name");
    catalog.AddItem(item);
    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Apple"));
    auto size = catalog.GetItemsCount("Apple");
    catalog.RemoveItem("Apple");
    ASSERT_EQ(catalog.GetItemsCount("Apple"), size - 1);
    MyTearDown();
}

TEST(ItemsCatalogTests, Remove_RemoveNonExistentItem_ThrowsError) {
    MySetUp();
    Crafting::ItemsCatalog::Create();
    auto catalog = Crafting::ItemsCatalog::Get();
    auto item = Crafting::Item::Create("Item Name");
    catalog.AddItem(item);
    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Apple"));
    catalog.AddItem(Crafting::Item::Create("Apple"));
    
    ASSERT_THROW(catalog.RemoveItem("Orange"), std::runtime_error);
    
    MyTearDown();
}
