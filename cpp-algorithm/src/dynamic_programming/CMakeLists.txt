find_package(GSL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/include)

macro(add_library_target target)
    add_library(${target} STATIC "${target}.cpp")
    target_link_libraries(${target} PRIVATE ${ARGN})
    set_property(TARGET ${target} PROPERTY CXX_STANDARD 20)
endmacro()

add_library_target(fibonacci_number)
add_library_target(interval_subset_sum_problem)
add_library_target(longest_common_subsequence GSL::gsl)
# add_library_target(matrix_chain)
add_library_target(rod_cutting)
