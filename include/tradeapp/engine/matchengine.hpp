#include <memory>
#include <string>
#include "errors.hpp"
#include "logger.hpp"
#include "events.hpp"
#include "orderbook.hpp"

class MatchEngine
{
private:
    std::unique_ptr<OrderBook> orderbook;
    std::shared_ptr<Logger> logger; // todo: system provides

public:
    MatchEngine();
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
