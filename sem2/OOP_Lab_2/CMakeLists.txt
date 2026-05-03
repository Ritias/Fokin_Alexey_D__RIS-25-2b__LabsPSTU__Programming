cmake_minimum_required(VERSION 4.2)
project(LabOOP2)

set(CMAKE_CXX_STANDARD 14)

include_directories(LabOOP2)

add_executable(LabOOP2
        LabOOP2/LabOOP2.cpp
        LabOOP2/Pay.cpp
        LabOOP2/Pay.h)
