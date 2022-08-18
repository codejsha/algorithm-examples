include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/graph)

enable_testing()

add_executable(bellman_ford_test "bellman_ford_test.cpp" "${CMAKE_SOURCE_DIR}/src/graph/bellman_ford.cpp")
target_link_libraries(bellman_ford_test PRIVATE common_util gtest_main)

add_executable(breadth_first_search_test "breadth_first_search_test.cpp" "${CMAKE_SOURCE_DIR}/src/graph/breadth_first_search.cpp")
target_link_libraries(breadth_first_search_test PRIVATE common_util gtest_main)

add_executable(depth_first_search_test "depth_first_search_test.cpp" "${CMAKE_SOURCE_DIR}/src/graph/depth_first_search.cpp")
target_link_libraries(depth_first_search_test PRIVATE common_util gtest_main)

add_executable(dijkstra_test "dijkstra_test.cpp" "${CMAKE_SOURCE_DIR}/src/graph/dijkstra.cpp")
target_link_libraries(dijkstra_test PRIVATE common_util gtest_main)

include(GoogleTest)
gtest_discover_tests(
	bellman_ford_test
	breadth_first_search_test
	depth_first_search_test
	dijkstra_test
)
