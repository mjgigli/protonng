find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# NNG transport address tests
add_executable(test-tcp-address test_tcp_address.cpp)
target_link_libraries(test-tcp-address ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(test-tcp-address protonng)
add_test(test-tcp-address test-tcp-address)

add_executable(test-ipc-address test_ipc_address.cpp)
target_link_libraries(test-ipc-address ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(test-ipc-address protonng)
add_test(test-ipc-address test-ipc-address)

add_executable(test-inproc-address test_inproc_address.cpp)
target_link_libraries(test-inproc-address ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(test-inproc-address protonng)
add_test(test-inproc-address test-inproc-address)
