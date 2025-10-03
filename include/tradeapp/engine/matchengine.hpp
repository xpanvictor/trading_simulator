#pragma once

#include <memory>
#include <string>
#include "tradeapp/model/errors.hpp"
#include "tradeapp/engine/logger.hpp"
#include "tradeapp/model/events.hpp"
#include "tradeapp/engine/orderbook.hpp"

class MatchEngine
{
private:
    std::unique_ptr<OrderBook> orderbook;
    Logger &logger; // todo: system provides

public:
    MatchEngine(Logger &l);
    /// @brief  creates & matches order
    /// @param ot
    /// @param userId
    /// @param quantity
    /// @param price
    /// @return
    Order placeOrder(
        EOrderType ot,
        long userId,
        long quantity,
        long price);
};
