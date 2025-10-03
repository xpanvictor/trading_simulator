#pragma once
#include <string>

class Trade
{
private:
public:
    const long id;
    const int timestamp;
    const long sellerId;
    const long buyerId;
    const long amount;
    const long quantity;

    Trade(long id, int timestamp, long sellerId, long buyerId, long amount, long quantity);

    std::string toString() const
    {
        return "trade: " + std::to_string(sellerId) + "->" + std::to_string(buyerId) + " ;Units: " + std::to_string(quantity) + " for: $" + std::to_string(amount);
    }
};
