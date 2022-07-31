add_library(combination "combination.cpp")
target_link_libraries(combination PRIVATE common_util)
set_property(TARGET combination PROPERTY CXX_STANDARD 20)

