cmake_minimum_required(VERSION 3.1)
project(protonng)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Pull in abseil-cpp library and googletest
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/CMake)
include(CMake/DownloadAbseil.cmake)
include(CMake/DownloadGTest.cmake)
