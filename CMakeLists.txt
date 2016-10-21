cmake_minimum_required(VERSION 3.6)
project(APKX)

find_package(Boost 1.60.0)

if (Boost_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lpthread")

    set(SOURCE_FILES main.cpp Package.cpp Checkpoint.cpp PackageGen.cpp Destination.cpp Airplane.cpp PackageQueue.cpp)
    add_executable(APKX ${SOURCE_FILES})
endif ()