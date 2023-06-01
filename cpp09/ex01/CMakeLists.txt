cmake_minimum_required(VERSION 3.24)
project(ex01)

set(CMAKE_CXX_STANDARD 98)

include_directories(include)
add_executable(ex01 src/main.cpp src/RPN.cpp)
