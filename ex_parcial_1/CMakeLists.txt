cmake_minimum_required(VERSION 2.8)
project(practica_2)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

add_executable(build/filter_exe 
src/filter.cpp)

add_executable(build/matrix_exe 
src/matrix.cpp)