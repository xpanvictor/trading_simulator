# all implementation files
file(GLOB SOURCE_FILES "*.cpp")

# link_libraries()
add_library(
    TradingEngine
    STATIC
    ${SOURCE_FILES}
)

# headers
target_include_directories(
    TradingEngine
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)