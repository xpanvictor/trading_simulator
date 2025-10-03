#pragma once

#include <string>
#include "tradeapp/model/order.hpp"
#include "tradeapp/model/trade.hpp"

namespace tradeapp
{
    class Event
    {
    public:
        std::string title;
        std::string msg;
        Event(std::string title, std::string msg) : title{title}, msg{msg} {}
        std::string format() const
        {
            return "Event->{" + title + "}: " + msg;
        }
        virtual ~Event() = default;
    };

    class OrderCreatedEvent : public Event
    {
    public:
        explicit OrderCreatedEvent(const Order &order) : Event{"OrderCreated", order.toString()} {}
    };

    class TradeCreatedEvent : public Event
    {
    public:
        explicit TradeCreatedEvent(const Trade &trade) : Event{"TradeCreated", trade.toString()} {}
    };
}
