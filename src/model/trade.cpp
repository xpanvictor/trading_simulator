#include <tradeapp/model/trade.hpp>

Trade::Trade(long id, int timestamp, long sellerId, long buyerId, long amount, long quantity)
    : id{id}, timestamp{timestamp}, sellerId{sellerId}, buyerId{buyerId}, amount{amount}, quantity{quantity} {}
