cmake_minimum_required(VERSION 3.16)	

project("test")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -pthread --coverage")
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic -pthread --coverage")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TESTS test_init.cpp stress_test.cpp test_custom_errors.cpp test_io.cpp test_list.cpp test_hash.cpp test_hashtable_find.cpp)
set(SOURCE "../src/io.c" "../src/hash.c" "../src/list.c" "../src/custom_errors.c")

include_directories("../headers/")
add_executable(singlethread_test ${TESTS} ${SOURCE} ${HEADERS})
add_executable(multithread_test ${TESTS} ${SOURCE} ${HEADERS})


target_link_libraries(singlethread_test singlethread_lib)
target_link_libraries(singlethread_test ${GTEST_LIBRARIES} pthread)

target_link_libraries(multithread_test multithread_lib)
target_link_libraries(multithread_test ${GTEST_LIBRARIES} pthread)