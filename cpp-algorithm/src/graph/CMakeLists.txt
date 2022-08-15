include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_library(breadth_first_search "breadth_first_search.cpp")
target_link_libraries(breadth_first_search PRIVATE common_util)
set_property(TARGET breadth_first_search PROPERTY CXX_STANDARD 20)
