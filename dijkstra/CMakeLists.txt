cmake_minimum_required(VERSION 3.17)
project(randomDijkstra C)

set(CMAKE_C_STANDARD 99)

add_executable(build/random_dijkstra.exe
include/dijkstra.h
include/randomGraph.h
include/menu.h
src/dijkstra.c
src/randomGraph.c
src/menu.c
src/random_dijkstra.c)