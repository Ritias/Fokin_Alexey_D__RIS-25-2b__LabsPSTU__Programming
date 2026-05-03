cmake_minimum_required(VERSION 4.2)
project(LabOOP7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LabOOP7
        LabOOP7.cpp
        List.h
        Pair.cpp
        Pair.h)
