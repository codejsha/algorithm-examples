find_package(GTest REQUIRED)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/heap)

macro(add_target_header_test target)
    string(REPLACE ".cpp" "" target_name ${target})
    add_executable(${target_name} ${target})
    target_link_libraries(${target_name} PRIVATE GTest::gtest_main ${ARGN})
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target_name} PUBLIC "/Zi")
        target_link_options(${target_name} PUBLIC "/INCREMENTAL")
    endif()
    gtest_discover_tests(${target_name} DISCOVERY_MODE PRE_TEST)
endmacro()

add_target_header_test(closest_star_test.cpp)
add_target_header_test(merge_sorted_array_test.cpp)
add_target_header_test(online_data_median_test.cpp)
add_target_header_test(sort_increasing_decreasing_array_test.cpp)
