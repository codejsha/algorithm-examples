include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_library(activity_selection "activity_selection.cpp")
target_link_libraries(activity_selection PRIVATE common_util)
set_property(TARGET activity_selection PROPERTY CXX_STANDARD 20)
