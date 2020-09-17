cmake_minimum_required(VERSION 2.8)
project(practica_2)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

add_executable(build/counter_exe 
src/counter.cpp)

add_executable(build/occurrence_exe 
src/occurrence.cpp)

add_executable(build/words_exe 
src/words.cpp)

add_executable(build/hangman_exe 
src/hangman.cpp)