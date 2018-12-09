# Additional target to run clang-tidy and clang-format

# Get all project files, ignoring test files
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

find_program(CLANG_TIDY "clang-tidy")
if(CLANG_TIDY)
    add_custom_target(
        clang-tidy ALL
        COMMAND /usr/bin/clang-tidy
        ${SOURCE_FILES}
        -p ${CMAKE_CURRENT_BINARY_DIR}
        -config=''
    )
endif()
