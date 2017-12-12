cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE Debug)
project(lexer)


set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_library(lexer lexer.cc)
add_library(parser parser.cc)
add_library(multi multi.cc)
#add_executable(mutex mutex.cc)



# Start Test Stuff
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(lexer_test lexer_test.cc)
target_link_libraries(lexer_test lexer)
target_link_libraries(lexer_test ${GTEST_BOTH_LIBRARIES})



add_executable(parser_test parser_test.cc)
target_link_libraries(parser_test lexer parser)
target_link_libraries(parser_test ${GTEST_BOTH_LIBRARIES})

add_executable(multi_test multi_test.cc)
target_link_libraries(multi_test lexer multi)
target_link_libraries(multi_test ${GTEST_BOTH_LIBRARIES})

add_test(NAME LexerTests COMMAND lexer_test)
add_test(NAME ParserTests COMMAND parser_test)
add_test(NAME MultiTests COMMAND multi_test)
