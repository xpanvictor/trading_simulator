#pragma once
#include <string>

namespace tradeapp
{
    std::string bracketString(const std::string &msg)
    {
        return "[" + msg + "]";
    }
};