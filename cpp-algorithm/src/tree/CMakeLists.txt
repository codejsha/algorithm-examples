include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/tree)

macro(add_library_target target)
    add_library(${target} STATIC "${target}.cpp")
    target_link_libraries(${target} PRIVATE ${ARGN})
    set_property(TARGET ${target} PROPERTY CXX_STANDARD 20)
endmacro()

add_library_target(b_tree)
add_library_target(balanced_tree_status)
add_library_target(binary_tree_exterior)
add_library_target(leaf_node_list)
add_library_target(lowest_common_ancestor)
add_library_target(right_sibling)
add_library_target(sum_root_to_leaf)
add_library_target(tree_symmetric)
