include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_library(interval_subset_sum_problem "interval_subset_sum_problem.cpp")
target_link_libraries(interval_subset_sum_problem PRIVATE common_util)
set_property(TARGET interval_subset_sum_problem PROPERTY CXX_STANDARD 20)
