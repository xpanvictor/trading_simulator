#pragma once

#include <string>
#include <ostream>
#include "tradeapp/model/enums.hpp"
#include "tradeapp/utils/time.hpp"

class Order
{
private:
    long price;
    long quantity;
    long id;
    int timestamp;

public:
    long traderId;
    EOrderType orderType;
    Order(long id, long traderId, long price, long quantity, EOrderType ot);

    // Getter methods for immutable-like access
    long getPrice() const;
    long getQuantity() const;
    long getId() const { return id; }
    int getTimestamp() const { return timestamp; }
    EOrderType getOrderType() const { return orderType; }

    std::string toString() const & { return "order_id: " + std::to_string(id); };
    friend std::ostream &operator<<(std::ostream &os, const Order &order);
    bool operator==(const Order &secondOrder);
    // comparators
    friend struct BuyCompare;
    friend struct SellCompare;
};

/// highest price on top
struct BuyCompare
{
    bool operator()(const Order &a, const Order &b) const
    {
        if (a.price == b.price)
        {
            return a.timestamp > b.timestamp; // older order takes priority
        }
        return a.price < b.price;
    }
};

/// lowest price on top
struct SellCompare
{
    bool operator()(const Order &a, const Order &b) const
    {
        if (a.price == b.price)
        {
            return a.timestamp > b.timestamp;
        }
        return a.price > b.price;
    }
};
