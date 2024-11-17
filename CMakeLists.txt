cmake_minimum_required(VERSION 3.30)
project(memdumper)

set(CMAKE_CXX_STANDARD 20)

add_executable(memdumper src/main.cpp
        src/managers/manager.cpp
        include/manager.h)
