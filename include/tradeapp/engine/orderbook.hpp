#pragma once

#include <order.hpp>
#include <trade.hpp>
#include <vector>
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

    // todo: use queues
    std::vector<Order> buyOrders;
    std::vector<Order> sellOrders;
    // todo: use LRU cache
    std::vector<Trade> recentTrades;

    // configurations
    OrderBookConfigSnapshot generateSnapshot();

public:
    OrderBook();
    OrderBook(OrderBookConfigSnapshot);

    // Order management
    long incrementOrderCounter();
    void addOrder(const Order &order);
    // throws if no match
    std::optional<std::reference_wrapper<Order>> findMatch(long orderId);
    void removeOrder(long orderId);
    void removeOrders(const std::vector<long> &orderIds);

    // trade system
    Trade makeTrade(const Trade &trade);
    long incrementTradeCounter();

    // manage snapshots & co
    ~OrderBook();
};