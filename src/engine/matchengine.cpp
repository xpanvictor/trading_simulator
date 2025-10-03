#include "tradeapp/engine/matchengine.hpp"
#include "tradeapp/engine/system.hpp"
using namespace std;

MatchEngine::MatchEngine(Logger &lg)
    : logger{lg}, orderbook{make_unique<OrderBook>()}
{
}

// placeOrder
// creates a new order in the book
// checks for match & creates trade
// logs all actions
Order MatchEngine::placeOrder(
    EOrderType ot,
    long userId,
    long quantity,
    long price)
{
    long orderNewCounter = 1;
    Order userOrder{orderNewCounter, userId, price, quantity, ot};
    // include order
    // orderbook->addOrder(userOrder);

    // auto matchedOrder = orderbook->findMatch(userOrder.id);
    // if (auto match = orderbook->findMatch(userOrder.id))
    // {
    //     Order &matchedOrder = match->get();
    //     // create trade
    //     long tradeNewCounter = orderbook->incrementTradeCounter();
    //     Trade generatedTrade = tradeappcore::createTrade(tradeNewCounter, userOrder, matchedOrder);
    //     orderbook->makeTrade(generatedTrade);
    //     // remove orders
    //     orderbook->removeOrders({userOrder.id, matchedOrder.id});
    //     // pass to persistence
    // }
    tradeapp::OrderCreatedEvent orderCreatedEv(userOrder);
    logger.logEvent(orderCreatedEv);
    return userOrder;
}
