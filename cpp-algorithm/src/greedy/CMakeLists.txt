include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/tree)

add_library(activity_selection "activity_selection.cpp")
target_link_libraries(activity_selection PRIVATE common_util)
set_property(TARGET activity_selection PROPERTY CXX_STANDARD 20)

add_library(huffman_code "huffman_code.cpp" "${CMAKE_SOURCE_DIR}/src/tree/tree.h")
target_link_libraries(huffman_code PRIVATE common_util)
set_property(TARGET huffman_code PROPERTY CXX_STANDARD 20)
