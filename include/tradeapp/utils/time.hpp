#pragma once
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

namespace tradeapp
{
    time_t fetchCurrTime()
    {
        return time(0);
    }
    tm fetchLocalTime()
    {
        time_t now = fetchCurrTime();
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
