cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE Debug)
project(chap2)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_library(lexer lexer.cc)
add_library(multi multi.cc)
#add_executable(mutex mutex.cc)



# Start Test Stuff
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()


file(GLOB TEST_SRCS *_test.cc)

add_executable(all_tests ${TEST_SRCS})
target_link_libraries(all_tests multi lexer ${GTEST_BOTH_LIBRARIES})


add_test(NAME Tests COMMAND all_tests)
