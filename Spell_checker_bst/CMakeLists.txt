cmake_minimum_required(VERSION 3.17)
project(Assignment_3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-static")

add_executable(spell_checker
        src/main.cpp
        src/binary_search_tree.cpp
        src/binary_search_tree.h
        src/spell_checker.cpp
        src/spell_checker.h
)
