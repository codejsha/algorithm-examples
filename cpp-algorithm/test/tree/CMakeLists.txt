find_package(GTest REQUIRED)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/tree)

macro(add_target_test target)
    string(REPLACE "_test" "" target_name ${target})
    add_executable(${target} "${target}.cpp" "${CMAKE_SOURCE_DIR}/src/tree/${target_name}.cpp")
    target_link_libraries(${target} PRIVATE GTest::gtest_main ${ARGN})
    gtest_discover_tests(${target})
    if(MSVC)
        ### Edit and Continue for CMake projects
        target_compile_options(${target} PUBLIC "/Zi")
        target_link_options(${target} PUBLIC "/INCREMENTAL")
    endif()
endmacro()

add_target_test(binary_search_tree_test)
add_target_test(b_tree_test)
# add_target_test(red_black_tree_test)
