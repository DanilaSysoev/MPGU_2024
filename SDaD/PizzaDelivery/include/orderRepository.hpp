#pragma once
#ifndef ORDERREPOSITORY_HPP
#define ORDERREPOSITORY_HPP

#include<vector>
#include "entities.hpp"

void addOrder(
    const std::vector<Pizza>& pizzaList, std::vector<Order>& orders
);
void deliveryOrder(std::vector<Order>& orders);
void cancelOrder(std::vector<Order>& orders);
void allOrders(const std::vector<Order>& orders);
void notDeliveredOrders(const std::vector<Order>& orders);

#endif