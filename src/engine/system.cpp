#include "tradeapp/engine/system.hpp"
#include "tradeapp/utils/time.hpp"

TradeCreationRemnant tradeappcore::createTrade(long tradeId, const Order &sellOrder, const Order &buyOrder)
{
    long sellQuantityDelta = sellOrder.getQuantity() - buyOrder.getQuantity();
    int timestamp = tradeapp::fetchCurrTime();

    Trade trade{
        tradeId,
        timestamp,
        sellOrder.traderId,
        buyOrder.traderId,
        sellOrder.getPrice(),
        min(sellOrder.getQuantity(), buyOrder.getQuantity())};

    if (sellQuantityDelta == 0)
    {
        return TradeCreationRemnant{
            trade,
            newOrderRef : nullopt
        };
    }

    bool isSellRemnant = sellQuantityDelta > 0;
    // todo
}
