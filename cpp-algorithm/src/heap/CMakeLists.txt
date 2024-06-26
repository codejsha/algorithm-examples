include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/heap)

macro(add_library_target target)
    string(REPLACE ".cpp" "" target_name ${target})
    add_library(${target_name} STATIC ${target})
    target_link_libraries(${target_name} PRIVATE ${ARGN})
endmacro()

add_library_target(closest_star.cpp)
add_library_target(online_data_median.cpp)
add_library_target(sort_increasing_decreasing_array.cpp)
