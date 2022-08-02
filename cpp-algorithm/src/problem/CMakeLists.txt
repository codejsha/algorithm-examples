include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_library(interval_subset_sum_problem "interval_subset_sum_problem.cpp")
target_link_libraries(interval_subset_sum_problem PRIVATE common_util)
set_property(TARGET interval_subset_sum_problem PROPERTY CXX_STANDARD 20)

add_library(rod_cutting_problem "rod_cutting_problem.cpp")
target_link_libraries(rod_cutting_problem PRIVATE common_util)
set_property(TARGET rod_cutting_problem PROPERTY CXX_STANDARD 20)
