cmake_minimum_required(VERSION 4.2)
project(LabOOP4)

set(CMAKE_CXX_STANDARD 14)

include_directories(LabOOP4)

add_executable(LabOOP4
        LabOOP4/LabOOP4.cpp
        LabOOP4/Person.cpp
        LabOOP4/Person.h
        LabOOP4/Student.cpp
        LabOOP4/Student.h)
