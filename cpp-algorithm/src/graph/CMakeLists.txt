include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_library(bellman_ford "bellman_ford.cpp" "graph.h")
target_link_libraries(bellman_ford PRIVATE common_util)
set_property(TARGET bellman_ford PROPERTY CXX_STANDARD 20)

add_library(breadth_first_search "breadth_first_search.cpp" "graph.h")
target_link_libraries(breadth_first_search PRIVATE common_util)
set_property(TARGET breadth_first_search PROPERTY CXX_STANDARD 20)

add_library(depth_first_search "depth_first_search.cpp" "graph.h")
target_link_libraries(depth_first_search PRIVATE common_util)
set_property(TARGET depth_first_search PROPERTY CXX_STANDARD 20)
