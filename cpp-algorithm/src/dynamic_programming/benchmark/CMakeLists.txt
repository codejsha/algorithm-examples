find_package(GSL REQUIRED)
find_package(benchmark REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/dynamic_programming)

macro(add_target_benchmark target)
    string(REPLACE "_benchmark" "" target_name ${target})
    add_executable(${target} "${target}.cpp" "${CMAKE_SOURCE_DIR}/src/dynamic_programming/${target_name}.cpp")
    target_link_libraries(${target} PRIVATE benchmark::benchmark_main ${ARGN})
    target_compile_definitions(${target} PUBLIC -DBENCHMARK_STATIC_DEFINE)
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target} PUBLIC "/Zi")
        target_link_options(${target} PUBLIC "/INCREMENTAL")
    endif()
endmacro()

add_target_benchmark(fibonacci_number_benchmark)
add_target_benchmark(interval_subset_sum_problem_benchmark)
# add_target_benchmark(longest_common_subsequence_benchmark GSL::gsl)
# add_target_benchmark(matrix_chain_benchmark)
add_target_benchmark(rod_cutting_benchmark)
