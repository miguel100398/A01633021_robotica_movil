cmake_minimum_required(VERSION 2.8)
project(practica_2)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

add_executable(build/main_students_exe 
include/students.hpp
include/group.hpp
src/students.cpp
src/group.cpp
src/main_students.cpp)

add_executable(build/main_bank_exe
include/client.hpp
include/node_linkedList.hpp
include/bank.hpp
src/client.cpp
src/node_linkedList.tpp
src/bank.cpp
src/main_bank.cpp
)
