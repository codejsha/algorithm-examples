include_directories(${CMAKE_SOURCE_DIR}/src/include)

macro(add_library_target target)
	add_library(${target} STATIC "${target}.cpp")
	target_link_libraries(${target} PRIVATE ${ARGN})
	set_property(TARGET ${target} PROPERTY CXX_STANDARD 20)
endmacro()

add_library_target(binary_search_tree)
add_library_target(b_tree)
# add_library_target(read_black_tree)
