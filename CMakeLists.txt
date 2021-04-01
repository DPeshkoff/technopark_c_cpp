cmake_minimum_required(VERSION 3.16)	

project(techopark_c_cpp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -pthread --coverage")
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic -pthread --coverage")

add_subdirectory(multithread)
add_subdirectory(singlethread)
add_subdirectory(test)

set(SOURCE src/io.c src/hash.c src/list.c src/custom_errors.c)

include_directories(headers)

add_executable(main_single main.c ${SOURCE} ${HEADERS})
target_link_libraries(main_single LINK_PUBLIC singlethread_lib)

add_executable(main_multiple main.c ${SOURCE} ${HEADERS})
target_link_libraries(main_multiple LINK_PUBLIC multithread_lib)