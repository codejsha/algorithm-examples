include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/linked_list)

macro(add_library_target target)
    add_library(${target} STATIC "${target}.cpp")
    target_link_libraries(${target} PRIVATE ${ARGN})
    set_property(TARGET ${target} PROPERTY CXX_STANDARD 20)
endmacro()

add_library_target(list_cycle)
add_library_target(merge_list)
add_library_target(reverse_list)
