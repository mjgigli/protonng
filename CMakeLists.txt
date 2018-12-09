cmake_minimum_required(VERSION 3.1)
project(protonng)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -fPIC")

# Define GNU standard installation directories
include(GNUInstallDirs)

# Pull in abseil-cpp library and googletest
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/CMake)
include(CMake/DownloadAbseil.cmake)
include(CMake/DownloadGTest.cmake)

# Pull in nng
find_package(nng CONFIG REQUIRED)

set(PROTONNG_SRCS
    src/protonng/address.cpp
    src/protonng/tcp_address.cpp
    src/protonng/ipc_address.cpp
    src/protonng/inproc_address.cpp
    src/protonng/service.cpp
    )

add_library(protonng STATIC ${PROTONNG_SRCS})

target_include_directories(protonng PUBLIC include)
target_link_libraries(protonng
    absl::base
    absl::strings
    nng::nng
    )

enable_testing()
add_subdirectory(test)
