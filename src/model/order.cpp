#include "tradeapp/model/order.hpp"
#include <limits>
#include <stdexcept>
#include <sstream>
using namespace std;

// max order quantity is max long for now
constexpr long MAX_ORDER_QUANTITY = std::numeric_limits<long>::max();

Order::Order(
    long id, long traderId, long price, long quantity, EOrderType ot)
    : id{id}, timestamp{tradeapp::fetchLocalTime().tm_sec}, traderId{traderId}, price{price}, quantity{quantity}, orderType{ot}
{
    if (quantity < 0 || quantity > MAX_ORDER_QUANTITY)
    {
        throw std::length_error("invalid quantity: " + std::to_string(quantity));
    }
    if (price < 0)
    {
        throw std::invalid_argument("invalid price");
    }
}

long Order::getPrice() const { return price; }
long Order::getQuantity() const { return quantity; }

bool Order::operator==(const Order &secondOrder)
{
    return id == secondOrder.id;
}

// Implement the stream operator
std::ostream &operator<<(std::ostream &os, const Order &order)
{
    os << order.toString();
    return os;
}