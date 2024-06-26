include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/queue)

macro(add_library_target target)
    string(REPLACE ".cpp" "" target_name ${target})
    add_library(${target_name} STATIC ${target})
    target_link_libraries(${target_name} PRIVATE ${ARGN})
endmacro()
