cmake_minimum_required(VERSION 3.16)	

project("multithread")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "--coverage -Wall -Werror -Wpedantic -pthread")
set(CMAKE_CXX_FLAGS "--coverage -Wall -Werror -Wpedantic -pthread")

include_directories("../headers/")
add_library(multithread_lib SHARED src/hashtable_find.c ${HEADERS})


target_include_directories(multithread_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})