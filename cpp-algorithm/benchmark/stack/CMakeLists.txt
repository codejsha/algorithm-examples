find_package(benchmark REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/stack)

macro(add_target_benchmark target)
    string(REPLACE "_benchmark" "" target_name ${target})
    add_executable(${target} "${target}.cpp" "${CMAKE_SOURCE_DIR}/src/stack/${target_name}.cpp")
    target_link_libraries(${target} PRIVATE benchmark::benchmark benchmark::benchmark_main ${ARGN})
    target_compile_definitions(${target} PUBLIC -DBENCHMARK_STATIC_DEFINE)
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target} PUBLIC "/Zi")
        target_link_options(${target} PUBLIC "/INCREMENTAL")
    endif()
endmacro()

macro(add_target_header_benchmark target)
    add_executable(${target} "${target}.cpp")
    target_link_libraries(${target} PRIVATE benchmark::benchmark benchmark::benchmark_main ${ARGN})
    target_compile_definitions(${target} PUBLIC -DBENCHMARK_STATIC_DEFINE)
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target} PUBLIC "/Zi")
        target_link_options(${target} PUBLIC "/INCREMENTAL")
    endif()
endmacro()

add_target_header_benchmark(max_stack_element_benchmark)
# add_target_benchmark(print_stack_benchmark)
