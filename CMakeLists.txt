cmake_minimum_required(VERSION 3.6)
project(APKX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Bagage.hpp)
add_executable(APKX ${SOURCE_FILES})