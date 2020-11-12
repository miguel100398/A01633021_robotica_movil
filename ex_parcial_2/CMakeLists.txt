cmake_minimum_required(VERSION 2.8)
project(examen_parcial_2)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

include_directories(include)

#dynamic library
add_library(OP3 SHARED 
src/OP3_Arm.cpp
src/A01633021.cpp)


#main program
add_executable(build/main_exe 
src/main.cpp
)

#main to test algorithms
add_executable(build/test_exe 
src/test.cpp
)

target_link_libraries(build/main_exe OP3)
target_link_libraries(build/test_exe OP3)
