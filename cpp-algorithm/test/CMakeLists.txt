set(CMAKE_CXX_STANDARD 20)

add_subdirectory(dynamic_programming)
add_subdirectory(graph)
add_subdirectory(greedy)
add_subdirectory(math)
add_subdirectory(problem_solving)
add_subdirectory(sort)
add_subdirectory(tree)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
