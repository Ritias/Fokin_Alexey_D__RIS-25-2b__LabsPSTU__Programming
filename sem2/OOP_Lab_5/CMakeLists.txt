cmake_minimum_required(VERSION 4.2)
project(LabOOP5)

set(CMAKE_CXX_STANDARD 14)

include_directories(LabOOP5)

add_executable(LabOOP5
        LabOOP5.cpp
        Person.cpp
        Person.h
        Student.cpp
        Student.h
Object.h
Object.cpp
Vector.h
Vector.cpp)