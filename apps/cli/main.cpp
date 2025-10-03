
#include <iostream>
#include "tradeapp/engine/logger.hpp"
#include "tradeapp/model/events.hpp"

int main()
{
    std::cout << "Trading Simulator CLI Started!" << std::endl;
    // testing logger
    Logger lg = Logger(std::cout);
    lg.log("just a test");
    return 0;
}
