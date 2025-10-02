#include <string>
#include <enums.hpp>

class Order
{
private:
    long price;
    long quantity;

public:
    const int id;
    const std::string traderId;
    const EOrderType orderType;
    Order(int id, std::string traderId, long price, long quantity, EOrderType ot);
    long getPrice();
    long getQuantity();
};
