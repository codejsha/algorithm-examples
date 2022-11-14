include_directories(${CMAKE_SOURCE_DIR}/src/include)

macro(add_library_target target)
	add_library(${target} STATIC "${target}.cpp")
	target_link_libraries(${target} PRIVATE ${ARGN})
	set_property(TARGET ${target} PROPERTY CXX_STANDARD 20)
endmacro()

add_library_target(combination sequence_util)
add_library_target(permutation)
