cmake_minimum_required(VERSION 3.16)	

project("singlethread")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "--coverage -Wall -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS "--coverage -Wall -Werror -Wpedantic")

include_directories("../headers/")
set(SOURCE src/hashtable_find.c)
add_library(singlethread_lib ${SOURCE} ${HEADERS})

target_include_directories(singlethread_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})