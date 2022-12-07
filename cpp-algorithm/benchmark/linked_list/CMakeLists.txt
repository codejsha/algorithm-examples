find_package(benchmark REQUIRED)

set(BENCHMARK_ENABLE_TESTING OFF)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/linked_list)

macro(add_target_benchmark target)
    string(REPLACE "_benchmark" "" target_name ${target})
    set(BENCHMARK_ENABLE_TESTING)
    add_executable(${target} "${target}.cpp" "${CMAKE_SOURCE_DIR}/src/linked_list/${target_name}.cpp")
    target_link_libraries(${target} PRIVATE benchmark::benchmark benchmark::benchmark_main ${ARGN})
    target_compile_definitions(${target} PUBLIC -DBENCHMARK_STATIC_DEFINE)
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target} PUBLIC "/Zi")
        target_link_options(${target} PUBLIC "/INCREMENTAL")
    endif()
endmacro()

add_target_benchmark(list_arithmetic_operation_benchmark)
add_target_benchmark(order_list_node_benchmark)
