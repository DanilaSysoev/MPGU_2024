#include "main.hpp"

using namespace ShopSystem;

int main()
{
    Goods g1(1);
    g1.SetName("Apple");
    g1.SetBuyPrice(100);
    g1.SetSellPrice(200);
    g1.SetCount(10);

    Goods g2(2);
    g2.SetName("Banana");
    g2.SetBuyPrice(50);
    g2.SetSellPrice(70);
    g2.SetCount(5);

    Goods g3(3);
    g3.SetName("Orange");
    g3.SetBuyPrice(80);
    g3.SetSellPrice(90);
    g3.SetCount(30);

    Store store("Happy fruits");
    store.AddGoods(g1);
    store.AddGoods(g2);
    store.AddGoods(g3);

    Terminal terminal(store);
    terminal.PrintReport();

    return 0;
}