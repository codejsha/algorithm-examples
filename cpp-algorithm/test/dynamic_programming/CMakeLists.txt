include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/dynamic_programming)

find_package(GSL REQUIRED)

enable_testing()

add_executable(fibonacci_number_test fibonacci_number_test.cpp "${CMAKE_SOURCE_DIR}/src/dynamic_programming/fibonacci_number.cpp")
target_link_libraries(fibonacci_number_test PRIVATE common_util gtest_main)

add_executable(longest_common_subsequence_test longest_common_subsequence_test.cpp "${CMAKE_SOURCE_DIR}/src/dynamic_programming/longest_common_subsequence.cpp")
target_link_libraries(longest_common_subsequence_test PRIVATE common_util gtest_main GSL::gsl)

add_executable(rod_cutting_test rod_cutting_test.cpp "${CMAKE_SOURCE_DIR}/src/dynamic_programming/rod_cutting.cpp")
target_link_libraries(rod_cutting_test PRIVATE common_util gtest_main)

include(GoogleTest)
gtest_discover_tests(fibonacci_number_test longest_common_subsequence_test rod_cutting_test)
