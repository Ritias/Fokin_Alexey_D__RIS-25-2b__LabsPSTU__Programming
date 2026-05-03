cmake_minimum_required(VERSION 4.2)
project(LabOOP8)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LabOOP8
        Dialog.cpp
        Dialog.h
        Event.h
        LabOOP8.cpp
        List.cpp
        List.h
        Magazin.cpp
        Magazin.h
        Object.cpp
        Object.h
        Print.cpp
        Print.h)
