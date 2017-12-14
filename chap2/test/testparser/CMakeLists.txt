

file(GLOB TEST_SRCS *.cc)

add_executable(all_tests ${TEST_SRCS})
target_link_libraries(all_tests libmulti liblexer libgtest libgmock)

add_test(NAME Tests COMMAND all_tests)
