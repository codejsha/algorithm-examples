include_directories(${CMAKE_SOURCE_DIR}/src/include)

macro(add_library_target target)
    string(REPLACE ".cpp" "" target_name ${target})
    add_library(${target_name} STATIC ${target})
    target_link_libraries(${target_name} PRIVATE ${ARGN})
endmacro()

add_library_target(combination.cpp sequence_util)
add_library_target(miller_rabin.cpp)
add_library_target(permutation.cpp)
