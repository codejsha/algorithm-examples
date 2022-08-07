include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/greedy)
include_directories(${CMAKE_SOURCE_DIR}/src/tree)

enable_testing()

add_executable(activity_selection_test "activity_selection_test.cpp" "${CMAKE_SOURCE_DIR}/src/greedy/activity_selection.cpp")
target_link_libraries(activity_selection_test PRIVATE common_util gtest_main)

add_executable(huffman_code_test "huffman_code_test.cpp" "${CMAKE_SOURCE_DIR}/src/greedy/huffman_code.cpp" "${CMAKE_SOURCE_DIR}/src/tree/tree.h")
target_link_libraries(huffman_code_test PRIVATE common_util gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(
	activity_selection_test
	huffman_code_test
)
