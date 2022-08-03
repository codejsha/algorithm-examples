include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_library(combination "combination.cpp")
target_link_libraries(combination PRIVATE common_util)
set_property(TARGET combination PROPERTY CXX_STANDARD 20)

add_library(permutation "permutation.cpp")
target_link_libraries(permutation PRIVATE common_util)
set_property(TARGET permutation PROPERTY CXX_STANDARD 20)
