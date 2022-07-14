add_library(tree STATIC binary_search_tree.cpp)
target_include_directories(tree PUBLIC .)

add_executable(binary_search_tree binary_search_tree.cpp)
target_link_libraries(binary_search_tree PRIVATE common_util)
set_property(TARGET binary_search_tree PROPERTY CXX_STANDARD 20)
