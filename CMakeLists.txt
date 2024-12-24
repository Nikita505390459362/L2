cmake_minimum_required(VERSION 3.29)
project(L2)

set(CMAKE_CXX_STANDARD 20)

add_executable(L2 main.cpp
        AeroFlot.cpp
        AeroFlot.h
        AEROFLOTWithCheck.cpp
        AEROFLOTWithCheck.h
)
