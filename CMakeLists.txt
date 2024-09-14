cmake_minimum_required(VERSION 3.29)
project(Lion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lion
    src/main.cpp
        src/lexer.cpp
        src/headers/lexer.h
        src/token.cpp
        src/headers/token.h)
