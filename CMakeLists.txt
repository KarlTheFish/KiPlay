cmake_minimum_required(VERSION 3.27)
project(KiPlay)

set(CMAKE_CXX_STANDARD 23)

add_executable(KiPlay main.cpp
        finder.cpp
        finder.h
        songObject.cpp
        songObject.h
)
