include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/math)

enable_testing()

add_executable(combination_test combination_test.cpp "${CMAKE_SOURCE_DIR}/src/math/combination.cpp")
target_link_libraries(combination_test PRIVATE common_util gtest_main)

include(GoogleTest)
gtest_discover_tests(combination_test permutation_test)
