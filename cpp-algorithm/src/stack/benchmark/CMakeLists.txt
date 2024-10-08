find_package(benchmark REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/stack)

macro(add_target_benchmark target)
    string(REPLACE ".cpp" "" target_name ${target})
    string(REPLACE "_benchmark.cpp" "" source_name ${target})
    add_executable(${target_name} ${target} "${CMAKE_SOURCE_DIR}/src/stack/${source_name}.cpp")
    target_link_libraries(${target_name} PRIVATE benchmark::benchmark_main ${ARGN})
    target_compile_definitions(${target_name} PUBLIC -DBENCHMARK_STATIC_DEFINE)
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target_name} PUBLIC "/Zi")
        target_link_options(${target_name} PUBLIC "/INCREMENTAL")
    endif()
endmacro()

macro(add_target_header_benchmark target)
    string(REPLACE ".cpp" "" target_name ${target})
    add_executable(${target_name} ${target})
    target_link_libraries(${target_name} PRIVATE benchmark::benchmark_main ${ARGN})
    target_compile_definitions(${target_name} PUBLIC -DBENCHMARK_STATIC_DEFINE)
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target_name} PUBLIC "/Zi")
        target_link_options(${target_name} PUBLIC "/INCREMENTAL")
    endif()
endmacro()

add_target_benchmark(check_pair_of_bracket_benchmark.cpp)
add_target_header_benchmark(max_stack_element_benchmark.cpp)
