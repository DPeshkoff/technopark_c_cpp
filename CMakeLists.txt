cmake_minimum_required(VERSION 3.16)	

project(techopark_c_cpp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "--coverage")

set(CMAKE_CXX_FLAGS "--coverage")

set(SOURCE main.c)	

include_directories("headers/")

set(SOURCE_LIB src/list.c src/data.c src/custom_errors.c src/io.c)

add_library(libs STATIC ${SOURCE_LIB})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests test/test_list.cpp test/test_custom_errors.cpp test/test_data.cpp test/test_io.cpp)


target_link_libraries(tests libs)

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

add_executable(main ${SOURCE})

target_link_libraries(main libs)





