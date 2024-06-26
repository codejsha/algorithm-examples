find_package(GTest REQUIRED)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/search)

macro(add_target_test target)
    string(REPLACE ".cpp" "" target_name ${target})
    string(REPLACE "_test.cpp" "" source_name ${target})
    add_executable(${target_name} ${target} "${CMAKE_SOURCE_DIR}/src/search/${source_name}.cpp")
    target_link_libraries(${target_name} PRIVATE GTest::gtest_main ${ARGN})
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target_name} PUBLIC "/Zi")
        target_link_options(${target_name} PUBLIC "/INCREMENTAL")
    endif()
    gtest_discover_tests(${target_name})
endmacro()

macro(add_target_header_test target)
    string(REPLACE ".cpp" "" target_name ${target})
    add_executable(${target_name} ${target})
    target_link_libraries(${target_name} PRIVATE GTest::gtest_main ${ARGN})
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target_name} PUBLIC "/Zi")
        target_link_options(${target_name} PUBLIC "/INCREMENTAL")
    endif()
    gtest_discover_tests(${target_name})
endmacro()

add_target_test(compute_square_root_test.cpp)
add_target_test(find_min_max_test.cpp)
add_target_test(quick_select_test.cpp)
add_target_test(search_sorted_array_test.cpp)
add_target_test(search_sorted_matrix_test.cpp)
