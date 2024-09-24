cmake_minimum_required(VERSION 3.28.1)
project(Lion VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(src/headers)

set(SOURCES
        src/main.cpp
        src/lexer.cpp
        src/token.cpp
)

set(HEADERS
        src/headers/lexer.h
        src/headers/token.h
)

add_executable(Lion ${SOURCES} ${HEADERS})

        src/token.cpp
        src/headers/token.h)
