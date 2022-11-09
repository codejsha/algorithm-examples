include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/greedy)
include_directories(${CMAKE_SOURCE_DIR}/src/tree)

enable_testing()
include(GoogleTest)

macro(add_target_test name)
    string(REPLACE "_test" "" target_name ${name})
	add_executable(${name} "${name}.cpp" "${CMAKE_SOURCE_DIR}/src/greedy/${target_name}.cpp")
	target_link_libraries(${name} PRIVATE common_util gtest_main ${ARGN})
	gtest_discover_tests(${name})
endmacro()

macro(add_target_tree_test name)
    string(REPLACE "_test" "" target_name ${name})
	add_executable(${name} "${name}.cpp" "${CMAKE_SOURCE_DIR}/src/greedy/${target_name}.cpp" "${CMAKE_SOURCE_DIR}/src/tree/tree.h")
	target_link_libraries(${name} PRIVATE common_util gtest_main ${ARGN})
	gtest_discover_tests(${name})
endmacro()

add_target_test(activity_selection_test)
add_target_tree_test(huffman_code_test)
