cmake_minimum_required(VERSION 3.24)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        CircularArrayLinkedList.cpp
        CircularArrayLinkedList.h
        Date.cpp
        Date.h
        DoubleDynamicLinkedList.cpp
        DoubleDynamicLinkedList.h
        Employee.cpp
        Employee.h
        main.cpp
        PermanentEmployee.cpp
        PermanentEmployee.h
        TemporaryEmployee.cpp
        TemporaryEmployee.h)
