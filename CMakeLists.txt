cmake_minimum_required(VERSION 3.30)
project(untitled5)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled5 src/main.cpp
        src/managers/manager.cpp
        include/manager.h)
