include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/heap)

macro(add_library_target target)
    add_library(${target} STATIC "${target}.cpp")
    target_link_libraries(${target} PRIVATE ${ARGN})
    set_property(TARGET ${target} PROPERTY CXX_STANDARD 20)
endmacro()
