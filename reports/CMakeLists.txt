cmake_minimum_required(VERSION 2.8)
project(report)

set(CMAKE_CXX_FLAGS "-std=c++98 -O3 ${CMAKE_CXX_FLAGS}")

add_executable(build/main_exe 
include/Record.hpp
include/CompareBehaviour.hpp
include/AscBehaviour.hpp
include/DescBehaviour.hpp
include/Map.hpp
include/ReportData.hpp
include/ReportGenerator.hpp
include/ReportRegion.hpp 
include/ReportCandaRegion.hpp 
include/ReportHorses.hpp 
include/Contro.hpp 
src/Record.cpp
src/ReportGenerator.cpp
src/ReportRegion.cpp
src/ReportCanadaRegion.cpp
src/ReportHorses.cpp
src/Contro.cpp 
src/main.cpp
)