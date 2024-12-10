cmake_minimum_required(VERSION 3.29)
project(L2)

set(CMAKE_CXX_STANDARD 20)

add_executable(L2 main.cpp
        AeroFlot.cpp
        AeroFlot.h
        AEROFLOTWithCheck.cpp
        AEROFLOTWithCheck.h
        l2-2/main.cpp
        l2-2/FileHandler.cpp
        l2-2/FileHandler.h
        l2-2/SentenceReverser.cpp
        l2-2/SentenceReverser.h)
