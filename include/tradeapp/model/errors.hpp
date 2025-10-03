#pragma once

#include <stdexcept>
#include <string>
using namespace std;

namespace tradeapp
{
    class TradeError : public runtime_error
    {
    public:
        explicit TradeError(const string &msg) : runtime_error{msg} {}
    };
    class OrderNotFoundError : public TradeError
    {
    public:
        explicit OrderNotFoundError(const string &msg) : TradeError{"OrderNotFoundError: " + msg} {}
    };
} // namespace tradeapp