find_package(fmt REQUIRED)
find_package(benchmark REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/tree)

macro(add_target_benchmark target)
    string(REPLACE ".cpp" "" target_name ${target})
    string(REPLACE "_benchmark.cpp" "" source_name ${target})
    add_executable(${target_name} ${target} "${CMAKE_SOURCE_DIR}/src/tree/${source_name}.cpp")
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

add_target_benchmark(b_tree_benchmark.cpp)
add_target_header_benchmark(binary_search_tree_benchmark.cpp)
add_target_benchmark(lowest_common_ancestor_benchmark.cpp)
