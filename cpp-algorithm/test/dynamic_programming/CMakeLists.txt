include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/dynamic_programming)

add_executable(fibonacci_number_test fibonacci_number_test.cpp "${CMAKE_SOURCE_DIR}/src/dynamic_programming/fibonacci_number.cpp")
target_link_libraries(fibonacci_number_test PRIVATE common_util gtest_main)

add_executable(rod_cutting_test rod_cutting_test.cpp "${CMAKE_SOURCE_DIR}/src/dynamic_programming/rod_cutting.cpp")
target_link_libraries(rod_cutting_test PRIVATE common_util gtest_main)

include(GoogleTest)
gtest_discover_tests(fibonacci_number_test rod_cutting_test)
