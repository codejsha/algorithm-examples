include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/sort)

enable_testing()

add_executable(insertion_sort_test insertion_sort_test.cpp ${CMAKE_SOURCE_DIR}/src/sort/insertion_sort.cpp)
target_link_libraries(insertion_sort_test PRIVATE common_util gtest gtest_main)

add_executable(selection_sort_test selection_sort_test.cpp ${CMAKE_SOURCE_DIR}/src/sort/selection_sort.cpp)
target_link_libraries(selection_sort_test PRIVATE common_util gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(insertion_sort_test selection_sort_test)
