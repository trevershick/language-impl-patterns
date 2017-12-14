add_library(liblexer lexer.cc)
add_library(libmulti multi.cc)


# Specify here the include directories exported
# by this library
target_include_directories(liblexer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_include_directories(libmulti PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)


