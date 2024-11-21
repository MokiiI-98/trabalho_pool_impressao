cmake_minimum_required(VERSION 3.29)
project(untitled4)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled4 main.cpp
        processo.cpp
        processo.h
        impressora.cpp
        impressora.h
        spool.cpp
        spool.h
        Logger.cpp
        Logger.h)
