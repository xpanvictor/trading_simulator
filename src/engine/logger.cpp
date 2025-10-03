#include "tradeapp/engine/logger.hpp"
#include "tradeapp/utils/time.hpp"
#include "tradeapp/utils/string.hpp"
using namespace std;

Logger::Logger(std::ostream &os_) : os{os_}
{
}

void Logger::log(const string &content)
{
    tm now = tradeapp::fetchLocalTime();
    os
        << "(LOG)-->"
        << tradeapp::bracketString(tradeapp::formatTime(&now))
        << " "
        << content
        << "\n";
}

void Logger::logEvent(const tradeapp::Event &ev)
{
    log(ev.format());
}
