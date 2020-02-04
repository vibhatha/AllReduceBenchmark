cmake_minimum_required(VERSION 3.15)
project(src)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_COMPILER /home/vibhatha/software/openmpi/build/bin/mpic++)

add_executable(src main.cpp)