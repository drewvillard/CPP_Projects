cmake_minimum_required(VERSION 3.17)
project(Assignment1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-static")


add_executable(edit
src/main.cpp
        src/linked_list.cpp
        include/linked_list.h
)

