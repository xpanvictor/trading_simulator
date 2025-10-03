#pragma once

#include <string>
#include <ostream>
#include "tradeapp/model/enums.hpp"

class Order
{
private:
    long price;
    long quantity;

public:
    const long id;
    long traderId;
    const EOrderType orderType;
    Order(long id, long traderId, long price, long quantity, EOrderType ot);
    long getPrice();
    long getQuantity();

    std::string toString() const & { return "order_id: " + std::to_string(id); };
    friend std::ostream &operator<<(std::ostream &os, const Order &order);
    bool operator==(const Order &secondOrder);
};
