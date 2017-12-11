cmake_minimum_required(VERSION 2.8)
project(project3_akin_ilerle_2017400252)

set(CMAKE_CXX_FLAGS "-std=c++0x")

set(SOURCE_FILES main.cpp Town.h Town.cpp io/FileIO.cpp io/FileIO.h Controller.cpp Controller.h)
add_executable(project3 ${SOURCE_FILES})