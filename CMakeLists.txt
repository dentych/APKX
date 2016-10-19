cmake_minimum_required(VERSION 3.6)
project(APKX)

find_package(Boost 1.60.0)

if (Boost_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

    set(SOURCE_FILES main.cpp Package.cpp Checkpoint.cpp BaggageGen.cpp Destination.cpp Collector.cpp)
    add_executable(APKX ${SOURCE_FILES})
endif ()