cmake_minimum_required(VERSION 3.25)

project(
        cpp_algorithm
        VERSION 1.0
        DESCRIPTION
        "Algorithm examples in C++"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()
add_subdirectory(src)
