include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/graph)

enable_testing()

add_executable(breadth_first_search_test "breadth_first_search_test.cpp" "${CMAKE_SOURCE_DIR}/src/graph/breadth_first_search.cpp")
target_link_libraries(breadth_first_search_test PRIVATE common_util gtest_main)

include(GoogleTest)
gtest_discover_tests(
	breadth_first_search_test
)
