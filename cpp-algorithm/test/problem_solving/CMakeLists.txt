include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/problem_solving)

enable_testing()

add_executable(interval_subset_sum_problem_test "interval_subset_sum_problem_test.cpp" "${CMAKE_SOURCE_DIR}/src/problem_solving/interval_subset_sum_problem.cpp")
target_link_libraries(interval_subset_sum_problem_test PRIVATE common_util gtest_main)

include(GoogleTest)
gtest_discover_tests(
	interval_subset_sum_problem_test
)
