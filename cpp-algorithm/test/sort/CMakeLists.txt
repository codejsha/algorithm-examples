include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/sort)

enable_testing()
include(GoogleTest)

macro(add_target_test name)
    string(REPLACE "_test" "" target_name ${name})
	add_executable(${name} "${name}.cpp" "${CMAKE_SOURCE_DIR}/src/sort/${target_name}.cpp")
	target_link_libraries(${name} PRIVATE common_util gtest_main ${ARGN})
	gtest_discover_tests(${name})
endmacro()

add_target_test(insertion_sort_test)
add_target_test(selection_sort_test)
