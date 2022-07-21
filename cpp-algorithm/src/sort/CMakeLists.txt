include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_library(insertion_sort insertion_sort.cpp)
target_link_libraries(insertion_sort PRIVATE common_util)
set_property(TARGET insertion_sort PROPERTY CXX_STANDARD 20)

add_library(selection_sort selection_sort.cpp)
target_link_libraries(selection_sort PRIVATE common_util)
set_property(TARGET selection_sort PROPERTY CXX_STANDARD 20)
