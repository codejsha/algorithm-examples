include_directories(${CMAKE_SOURCE_DIR}/src/include)

macro(add_library_target target)
    string(REPLACE ".cpp" "" target_name ${target})
    add_library(${target_name} STATIC ${target})
    target_link_libraries(${target_name} PRIVATE ${ARGN})
endmacro()

add_library_target(bellman_ford.cpp)
add_library_target(breadth_first_search.cpp)
add_library_target(depth_first_search.cpp)
add_library_target(dijkstra.cpp)
# add_library_target(floyd_warshall.cpp)
# add_library_target(kruskal.cpp)
# add_library_target(prim.cpp)
