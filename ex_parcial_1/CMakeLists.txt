cmake_minimum_required(VERSION 2.8)
project(examen_parcial_1)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

add_executable(build/examen_parcial_1_exe 
src/examen_parcial_1.cpp
src/read_file.cpp
src/fourier.cpp
src/convolution.cpp)


add_executable(build/read_file_test_exe 
src/read_file.cpp
tests/read_file_test.cpp)

add_executable(build/fourier_test_exe 
src/read_file.cpp
src/fourier.cpp
tests/fourier_test.cpp)

add_executable(build/convolution_test_exe 
src/convolution.cpp
tests/convolution_test.cpp)

