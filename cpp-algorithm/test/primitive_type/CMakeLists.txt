find_package(GTest REQUIRED)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/primitive_type)

enable_testing()

macro(add_target_test name)
    string(REPLACE "_test" "" target_name ${name})
	add_executable(${name} "${name}.cpp" "${CMAKE_SOURCE_DIR}/src/primitive_type/${target_name}.cpp")
	target_link_libraries(${name} PRIVATE GTest::gtest_main ${ARGN})
	gtest_discover_tests(${name})
endmacro()

add_target_test(arithmetic_operation_test)
# add_target_test(binary_exponentiation_test)
# add_target_test(closest_integer_test)
add_target_test(compute_parity_test)
# add_target_test(generate_random_number_test)
# add_target_test(integer_palindrome_test)
add_target_test(power_operation_test)
add_target_test(rectangle_intersection_test)
# add_target_test(reverse_bit_test)
# add_target_test(reverse_digit_test)
add_target_test(swap_bit_test)
