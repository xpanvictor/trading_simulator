#include "tradeapp/engine/orderbook.hpp"
#include "tradeapp/model/errors.hpp"
#include <algorithm>
using namespace std;

// Initialize static members
long OrderBook::orderCounter = 0;
long OrderBook::tradeCounter = 0;

OrderBook::OrderBook()
{
}

long OrderBook::incrementOrderCounter() { return ++orderCounter; }
long OrderBook::incrementTradeCounter() { return ++tradeCounter; }

void OrderBook::addOrder(const Order &order)
{
    switch (order.orderType)
    {
    case EOrderType::BUY:
        buyOrders.push_back(order);
        return;
    case EOrderType::SELL:
        sellOrders.push_back(order);
        return;
    default:
        throw tradeapp::InvalidOrderError("order type does not exist");
    }
}

optional<reference_wrapper<Order>> OrderBook::findMatch(long orderId)
{
    // todo
    return nullopt;
}

optional<reference_wrapper<vector<Order>::iterator>> OrderBook::findOrder(vector<Order> &storage, const Order &order)
{
    auto it = find(storage.begin(), storage.end(), order);
    if (it == storage.end())
    {
        return nullopt;
    }
    return ref(it);
}

void OrderBook::removeOrder(vector<Order> &storage, const Order &order)
{
    auto it = findOrder(storage, order);
    if (it.has_value())
    {
        storage.erase(it->get());
        return;
    }
    throw tradeapp::OrderNotFoundError("id: " + to_string(order.id));
}

void OrderBook::removeOrders(const vector<Order> &orders)
{
    for (const auto &order : orders)
    {
        switch (order.orderType)
        {
        case EOrderType::BUY:
            removeOrder(buyOrders, order);
            break;
        case EOrderType::SELL:
            removeOrder(sellOrders, order);
            break;

        default:
            throw tradeapp::InvalidOrderError("invalid order type");
            break;
        }
    }
}

Trade OrderBook::makeTrade(const Trade &trade)
{
    recentTrades.push_back(trade);
    return trade;
}

OrderBook::~OrderBook()
{
}
