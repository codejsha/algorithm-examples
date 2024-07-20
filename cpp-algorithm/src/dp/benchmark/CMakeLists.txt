find_package(GSL REQUIRED)
find_package(benchmark REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/dp)

macro(add_target_benchmark target)
    string(REPLACE ".cpp" "" target_name ${target})
    string(REPLACE "_benchmark.cpp" "" source_name ${target})
    add_executable(${target_name} ${target} "${CMAKE_SOURCE_DIR}/src/dp/${source_name}.cpp")
    target_link_libraries(${target_name} PRIVATE benchmark::benchmark_main ${ARGN})
    target_compile_definitions(${target_name} PUBLIC -DBENCHMARK_STATIC_DEFINE)
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target_name} PUBLIC "/Zi")
        target_link_options(${target_name} PUBLIC "/INCREMENTAL")
    endif()
endmacro()

add_target_benchmark(fibonacci_number_benchmark.cpp)
add_target_benchmark(interval_subset_sum_problem_benchmark.cpp)
add_target_benchmark(rod_cutting_benchmark.cpp)
