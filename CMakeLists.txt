cmake_minimum_required(VERSION 4.3)
project(Act1_1_Ordenamiento)

set(CMAKE_CXX_STANDARD 26)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-O2")

add_executable(Act1_1_Ordenamiento main.cpp)
