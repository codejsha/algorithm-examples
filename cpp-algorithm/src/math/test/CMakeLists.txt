find_package(GTest REQUIRED)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/math)

macro(add_target_test target)
    string(REPLACE "_test" "" target_name ${target})
    add_executable(${target} "${target}.cpp" "${CMAKE_SOURCE_DIR}/src/math/${target_name}.cpp")
    target_link_libraries(${target} PRIVATE GTest::gtest_main ${ARGN})
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target} PUBLIC "/Zi")
        target_link_options(${target} PUBLIC "/INCREMENTAL")
    endif()
    gtest_discover_tests(${target})
endmacro()

macro(add_target_header_test target)
    add_executable(${target} "${target}.cpp")
    target_link_libraries(${target} PRIVATE GTest::gtest_main ${ARGN})
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target} PUBLIC "/Zi")
        target_link_options(${target} PUBLIC "/INCREMENTAL")
    endif()
    gtest_discover_tests(${target})
endmacro()

add_target_test(combination_test sequence_util)
add_target_test(miller_rabin_test)
add_target_test(permutation_test)
