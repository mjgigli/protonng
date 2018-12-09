find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_SRCS
    test_inproc_address.cpp
    test_ipc_address.cpp
    test_tcp_address.cpp
    test_service.cpp
    )

# Service tests
foreach(TEST_FILE ${TEST_SRCS})
    get_filename_component(TEST_MODULE ${TEST_FILE} NAME_WE)
    message("Test ${TEST_MODULE}")
    add_executable(${TEST_MODULE} ${TEST_FILE})
    target_link_libraries(${TEST_MODULE} ${GTEST_BOTH_LIBRARIES} pthread)
    target_link_libraries(${TEST_MODULE} protonng)
    add_test(${TEST_MODULE} ${TEST_MODULE})
endforeach()
