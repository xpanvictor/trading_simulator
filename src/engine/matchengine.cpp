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
    long orderNewCounter = orderbook->incrementOrderCounter();
    Order userOrder{orderNewCounter, userId, price, quantity, ot};
    // include order
    orderbook->addOrder(userOrder);
    logger.logEvent(tradeapp::OrderCreatedEvent(userOrder));

    auto matchedOrder = orderbook->findMatch(userOrder.getId());
    if (auto match = orderbook->findMatch(userOrder.getId()))
    {
        Order &matchedOrder = match->get();
        // create trade
        long tradeNewCounter = orderbook->incrementTradeCounter();
        TradeCreationRemnant generatedTrade = tradeappcore::createTrade(tradeNewCounter, userOrder, matchedOrder);
        orderbook->makeTrade(generatedTrade.trade);
        logger.logEvent(tradeapp::TradeCreatedEvent(generatedTrade.trade));
        // remove orders
        orderbook->popOrders();
        // pass to persistence
    }
    return userOrder;
}
