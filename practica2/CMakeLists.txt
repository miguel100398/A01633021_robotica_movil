cmake_minimum_required(VERSION 2.8)
project(game)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

add_executable(game_exe 
src/main.cpp)