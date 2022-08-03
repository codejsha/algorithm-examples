include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_library(fibonacci_number "fibonacci_number.cpp")
target_link_libraries(fibonacci_number PRIVATE common_util)
set_property(TARGET fibonacci_number PROPERTY CXX_STANDARD 20)

add_library(rod_cutting "rod_cutting.cpp")
target_link_libraries(rod_cutting PRIVATE common_util)
set_property(TARGET rod_cutting PROPERTY CXX_STANDARD 20)
