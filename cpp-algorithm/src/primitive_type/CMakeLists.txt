include_directories(${CMAKE_SOURCE_DIR}/src/include)

macro(add_library_target target)
    add_library(${target} STATIC "${target}.cpp")
    target_link_libraries(${target} PRIVATE ${ARGN})
    set_property(TARGET ${target} PROPERTY CXX_STANDARD 20)
endmacro()

add_library_target(arithmetic_operation)
# add_library_target(binary_exponentiation)
# add_library_target(closest_integer)
add_library_target(compute_parity)
add_library_target(generate_random_number)
add_library_target(integer_palindrome)
add_library_target(power_operation)
add_library_target(rectangle_intersection)
# add_library_target(reverse_bit)
add_library_target(reverse_digit)
add_library_target(swap_bit)
