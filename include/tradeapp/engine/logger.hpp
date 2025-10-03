#include <ostream>
#include <ctime>
#include <memory>
#include "events.hpp"

class Logger
{
private:
    std::ostream &os;
    void log(const std::string &content);

public:
    Logger(std::ostream &os_);
    void logEvent(const tradeapp::Event &ev);
};
