
#include <iostream>
#include "tradeapp/engine/logger.hpp"
#include "tradeapp/engine/matchengine.hpp"
#include "tradeapp/model/events.hpp"

int main()
{
    std::cout << "Trading Simulator CLI Started!" << std::endl;
    // testing logger
    Logger lg = Logger(std::cout);
    MatchEngine eg{lg};
    Order od = eg.placeOrder(
        EOrderType::BUY,
        long{1},
        long{1}, long{1});
    return 0;
}
