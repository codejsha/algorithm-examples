find_package(GSL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/include)

macro(add_library_target target)
    string(REPLACE ".cpp" "" target_name ${target})
    add_library(${target_name} STATIC ${target})
    target_link_libraries(${target_name} PRIVATE ${ARGN})
endmacro()

add_library_target(fibonacci_number.cpp)
add_library_target(interval_subset_sum_problem.cpp)
add_library_target(longest_common_subsequence.cpp GSL::gsl)
# add_library_target(matrix_chain.cpp)
add_library_target(rod_cutting.cpp)
