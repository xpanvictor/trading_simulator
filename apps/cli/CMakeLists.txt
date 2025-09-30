file(GLOB APP_SOURCES "*.cpp")

# make exec target
add_executable(
    trading_simulator_cli
    ${APP_SOURCES}
)

# use the library from sources
target_link_libraries(
    trading_simulator_cli
    PRIVATE
    TradingEngine
)