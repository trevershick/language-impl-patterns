cmake_minimum_required(VERSION 2.8)
#set(CMAKE_BUILD_TYPE Debug)
project(chap2)

enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_subdirectory(lib)
add_subdirectory(test)
