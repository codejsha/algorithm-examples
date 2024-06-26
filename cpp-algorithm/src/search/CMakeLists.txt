include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/search)

macro(add_library_target target)
    string(REPLACE ".cpp" "" target_name ${target})
    add_library(${target_name} STATIC ${target})
    target_link_libraries(${target_name} PRIVATE ${ARGN})
endmacro()

add_library_target(compute_square_root.cpp)
add_library_target(find_min_max.cpp)
add_library_target(quick_select.cpp)
add_library_target(search_sorted_array.cpp)
add_library_target(search_sorted_matrix.cpp)
