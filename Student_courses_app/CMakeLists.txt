cmake_minimum_required(VERSION 3.23)
project(Assignment2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment2 src/main.cpp Student.h src/Student.cpp)

target_link_libraries(Assignment2)
