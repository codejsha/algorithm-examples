find_package(benchmark REQUIRED)

set(BENCHMARK_ENABLE_TESTING OFF)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/array)

macro(add_target_benchmark_test target)
    string(REPLACE "_benchmark_test" "" target_name ${target})
    set(BENCHMARK_ENABLE_TESTING)
    add_executable(${target} "${target}.cpp" "${CMAKE_SOURCE_DIR}/src/array/${target_name}.cpp")
    target_link_libraries(${target} PRIVATE benchmark::benchmark benchmark::benchmark_main ${ARGN})
    target_compile_definitions(${target} PUBLIC -DBENCHMARK_STATIC_DEFINE)
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target} PUBLIC "/Zi")
        target_link_options(${target} PUBLIC "/INCREMENTAL")
    endif()
endmacro()

add_target_benchmark_test(advancing_through_benchmark_test)
add_target_benchmark_test(arbitrary_precision_integer_benchmark_test)
add_target_benchmark_test(delete_element_benchmark_test)
add_target_benchmark_test(enumerate_prime_number_benchmark_test)
add_target_benchmark_test(random_data_sampling_benchmark_test)
add_target_benchmark_test(replace_element_benchmark_test)
add_target_benchmark_test(trade_stock_benchmark_test)
