include_directories(${CMAKE_SOURCE_DIR}/src/include)

macro(add_library_target target)
    string(REPLACE ".cpp" "" target_name ${target})
    add_library(${target_name} STATIC ${target})
    target_link_libraries(${target_name} PRIVATE ${ARGN})
endmacro()

add_library_target(h_index.cpp)
add_library_target(insertion_sort.cpp)
add_library_target(intersect_two_sorted_array.cpp)
add_library_target(merge_interval.cpp)
add_library_target(merge_two_sorted_array.cpp)
add_library_target(remove_first_name_duplicate.cpp)
add_library_target(selection_sort.cpp)
add_library_target(union_interval.cpp)
