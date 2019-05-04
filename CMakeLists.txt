cmake_minimum_required(VERSION 3.12.1)
project(os_jit)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,undefined")

add_executable(os_jit main.cpp my_func.cpp)