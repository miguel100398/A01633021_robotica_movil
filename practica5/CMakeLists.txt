cmake_minimum_required(VERSION 2.8)
project(practica_2)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

add_executable(build/fractions_exe 
src/fractions.cpp)

add_executable(build/students_exe 
src/students.cpp)