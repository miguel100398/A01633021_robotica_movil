cmake_minimum_required(VERSION 2.8)
project(practica_2)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

add_executable(build/students_main_exe 
include/students.hpp
include/group.hpp
src/students.cpp
src/group.cpp
src/main_students.cpp)
