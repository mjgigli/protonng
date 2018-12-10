# Downloads and unpacks abseil-cpp at configure time.  Based on the instructions
# at https://github.com/google/googletest/tree/master/googletest#incorporating-into-an-existing-cmake-project

# Download the latest abseil-cpp from Github master
configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt.abseil.in
  ${CMAKE_BINARY_DIR}/abseil-cpp-download/CMakeLists.txt
)

# Configure and build the downloaded abseil-cpp source
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/abseil-cpp-download )
if(result)
  message(FATAL_ERROR "CMake step for abseil-cpp failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/abseil-cpp-download)
if(result)
  message(FATAL_ERROR "Build step for abseil-cpp failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add abseil-cpp directly to our build. This defines the gtest and gtest_main
# targets.
add_subdirectory(${CMAKE_BINARY_DIR}/abseil-cpp-src
                 ${CMAKE_BINARY_DIR}/abseil-cpp-build
                 EXCLUDE_FROM_ALL)
