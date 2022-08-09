include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_library(binary_search_tree "binary_search_tree.cpp" "${CMAKE_SOURCE_DIR}/src/tree/tree.h")
target_link_libraries(binary_search_tree PRIVATE common_util)
set_property(TARGET binary_search_tree PROPERTY CXX_STANDARD 20)

add_library(b_tree "b_tree.cpp")
target_link_libraries(b_tree PRIVATE common_util)
set_property(TARGET b_tree PROPERTY CXX_STANDARD 20)
