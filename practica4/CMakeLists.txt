cmake_minimum_required(VERSION 2.8)
project(practica_2)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

add_executable(build/sort_exe 
src/sort.cpp)

add_executable(build/statistics_exe 
src/statistics.cpp)