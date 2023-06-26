cmake_minimum_required(VERSION 3.10)

project(curves)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-D_USE_MATH_DEFINES)

add_executable(Cuerves3d main.cpp curves.h curves.cpp)