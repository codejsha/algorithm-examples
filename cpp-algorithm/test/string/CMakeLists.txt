find_package(GTest REQUIRED)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/string)

enable_testing()

macro(add_target_test name)
    string(REPLACE "_test" "" target_name ${name})
	add_executable(${name} "${name}.cpp" "${CMAKE_SOURCE_DIR}/src/string/${target_name}.cpp")
	target_link_libraries(${name} PRIVATE GTest::gtest_main ${ARGN})
	gtest_discover_tests(${name})
endmacro()

add_target_test(convert_string_test)
add_target_test(ip_address_test)
add_target_test(look_and_say_test)
add_target_test(palindrome_test)
# add_target_test(print_snake_string_test)
add_target_test(roman_number_test)
# add_target_test(sheet_encoding_test)
