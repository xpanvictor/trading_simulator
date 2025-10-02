#include <order.hpp>
#include <trade.hpp>
#include <vector>

struct OrderBookConfigSnapshot
{
    int orderCounter;
    int tradeCounter;
};

// System in memory storage class
class OrderBook
{
private:
    static int orderCounter;
    static int tradeCounter;

    // todo: use queues
    std::vector<Order *> buyOrders;
    std::vector<Order *> sellOrders;
    // todo: use LRU cache
    std::vector<Trade *> recentTrades;

    // configurations
    OrderBookConfigSnapshot generateSnapshot();

public:
    OrderBook();
    OrderBook(OrderBookConfigSnapshot);

    void addOrder(Order *order);

    // trade system
    Trade *makeTrade();

    // manage snapshots & co
    ~OrderBook();
};