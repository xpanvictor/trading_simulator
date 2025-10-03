
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

namespace tradeapp
{
    tm fetchLocalTime()
    {
        time_t now = time(0);
        return *localtime(&now);
    }

    string formatTime(tm *rawTime)
    {
        // should separate this char->string conversion
        ostringstream oss;
        oss << put_time(rawTime, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }
};
