cmake_minimum_required(VERSION 3.15...4.00)

# project def
project(
    TradingSimulator
    VERSION 1.0
    DESCRIPTION "A trading simulator app!"
    LANGUAGES CXX
)

# standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# includes
include_directories(include)

# core logic 
add_subdirectory(src)
# cli
add_subdirectory(apps/cli)
