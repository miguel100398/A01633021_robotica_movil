cmake_minimum_required(VERSION 2.8)
project(practica_2)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

add_executable(build/supermarket_exe 
include/product.hpp
include/vegetable.hpp
include/drink.hpp
include/market.hpp
src/product.cpp
src/vegetable.cpp 
src/drink.cpp
src/main_product
src/market.cpp)

