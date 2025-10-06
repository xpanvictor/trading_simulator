#include "tradeapp/engine/system.hpp"
#include "tradeapp/utils/time.hpp"

Trade tradeappcore::createTrade(long tradeId, const Order &orderA, const Order &orderB)
{
    if (orderA.orderType == orderB.orderType)
    {
        throw tradeapp::TradeError("trade orders are of same type");
    }
    long sellQuantityDelta = orderA.getQuantity() - orderB.getQuantity();
    int timestamp = tradeapp::fetchCurrTime();
    const Order &sellOrder = orderA.orderType == EOrderType::SELL ? orderA : orderB;

    Trade trade{
        tradeId,
        timestamp,
        orderA.traderId,
        orderB.traderId,
        sellOrder.getPrice(),
        min(orderA.getQuantity(), orderB.getQuantity())};

    return trade;
    // Order book can handle the rest
}
