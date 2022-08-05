include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/greedy)

enable_testing()

add_executable(activity_selection_test activity_selection_test.cpp "${CMAKE_SOURCE_DIR}/src/greedy/activity_selection.cpp")
target_link_libraries(activity_selection_test PRIVATE common_util gtest_main)

include(GoogleTest)
gtest_discover_tests(activity_selection_test)
