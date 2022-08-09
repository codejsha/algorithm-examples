include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/tree)

enable_testing()

add_executable(binary_search_tree_test "binary_search_tree_test.cpp" "${CMAKE_SOURCE_DIR}/src/tree/binary_search_tree.cpp")
target_link_libraries(binary_search_tree_test PRIVATE common_util gtest gtest_main)

add_executable(b_tree_test "b_tree_test.cpp" "${CMAKE_SOURCE_DIR}/src/tree/b_tree.cpp")
target_link_libraries(b_tree_test PRIVATE common_util gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(
	binary_search_tree_test
	b_tree_test
)
