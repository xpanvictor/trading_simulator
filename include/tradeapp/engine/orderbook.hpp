#pragma once

#include "tradeapp/model/order.hpp"
#include "tradeapp/model/trade.hpp"
#include <vector>
#include <queue>
#include <optional>
#include <functional>
#include <span>

struct OrderBookConfigSnapshot
{
    long orderCounter;
    long tradeCounter;
};

// System in memory order management
class OrderBook
{
private:
    static long orderCounter;
    static long tradeCounter;

    std::priority_queue<Order, std::vector<Order>, BuyCompare> buyOrders;
    std::priority_queue<Order, std::vector<Order>, SellCompare> sellOrders;
    // todo: use LRU cache
    std::vector<Trade> recentTrades;

    std::optional<std::reference_wrapper<std::vector<Order>::iterator>> findOrder(std::vector<Order> &storage, const Order &order);

    // configurations
    // OrderBookConfigSnapshot generateSnapshot();

public:
    OrderBook() = default;
    // OrderBook(OrderBookConfigSnapshot);

    // Order management
    long incrementOrderCounter();
    void addOrder(const Order &order);
    // throws if no match
    std::optional<std::reference_wrapper<Order>> findMatch(long orderId);
    void popOrders();

    /// trade system
    /// Pops orders from book
    Trade makeTrade(const Trade &trade);
    long incrementTradeCounter();

    // manage snapshots & co
    ~OrderBook() = default;
};