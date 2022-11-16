find_package(GTest REQUIRED)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/problem_solving)

enable_testing()

macro(add_target_test target)
    string(REPLACE "_test" "" target_name ${target})
	add_executable(${target} "${target}.cpp" "${CMAKE_SOURCE_DIR}/src/problem_solving/${target_name}.cpp")
	target_link_libraries(${target} PRIVATE GTest::gtest_main ${ARGN})
	if(MSVC)
		### Edit and Continue for CMake projects
		target_compile_options(${target} PUBLIC "/Zi")
		target_link_options(${target} PUBLIC "/INCREMENTAL")
	endif()
	gtest_discover_tests(${target})
endmacro()

add_target_test(interval_subset_sum_problem_test)
