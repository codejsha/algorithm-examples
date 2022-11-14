find_package(GTest REQUIRED)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/array)

enable_testing()

macro(add_target_test name)
    string(REPLACE "_test" "" target_name ${name})
	add_executable(${name} "${name}.cpp" "${CMAKE_SOURCE_DIR}/src/array/${target_name}.cpp")
	target_link_libraries(${name} PRIVATE GTest::gtest_main ${ARGN})
	gtest_discover_tests(${name})
endmacro()

add_target_test(advancing_through_test)
add_target_test(arbitrary_precision_integer_test)
add_target_test(delete_element_test)
add_target_test(enumerate_prime_number_test)
# add_target_test(order_element_test)
add_target_test(random_data_sampling_test)
add_target_test(replace_element_test)
add_target_test(trade_stock_test)
