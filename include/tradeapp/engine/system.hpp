#pragma once

#include "tradeapp/model/trade.hpp"
#include "tradeapp/model/order.hpp"
#include "tradeapp/model/errors.hpp"

namespace tradeappcore
{
    Trade createTrade(long tradeId, const Order &orderA, const Order &orderB);
}; // tradeappcore namespace