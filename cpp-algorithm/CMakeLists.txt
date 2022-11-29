cmake_minimum_required(VERSION 3.16)

project(
	cpp_algorithm
	VERSION 1.0
	DESCRIPTION
		"Algorithm examples for C++"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)
enable_testing()
add_subdirectory(test)
