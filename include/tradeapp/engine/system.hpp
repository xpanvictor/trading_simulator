#pragma once

#include "tradeapp/model/trade.hpp"
#include "tradeapp/model/order.hpp"

struct TradeCreationRemnant
{
    Trade trade;
    std::optional<reference_wrapper<Order>> newOrderRef;
};
namespace tradeappcore
{
    TradeCreationRemnant createTrade(long tradeId, const Order &orderA, const Order &orderB);
}; // tradeappcore namespace