#pragma once

#include <ostream>
#include <ctime>
#include <memory>
#include "tradeapp/model/events.hpp"

class Logger
{
private:
    std::ostream &os;

public:
    Logger(std::ostream &os_);
    void log(const std::string &content);
    void logEvent(const tradeapp::Event &ev);
};
