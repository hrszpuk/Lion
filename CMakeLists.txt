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
        src/parser.cpp
)

set(HEADERS
        src/headers/lexer.h
        src/headers/token.h
        src/headers/parser.h
        src/headers/node.h
)

add_executable(Lion ${SOURCES} ${HEADERS})

# Google Test setup
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE TEST_FILES tests/test_*.cpp)

foreach(test_file ${TEST_FILES})
    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name} ${test_file} src/lexer.cpp src/token.cpp)
    target_link_libraries(${test_name} ${GTEST_LIBRARIES} pthread)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(Lion PRIVATE -Wall -Wextra -Wpedantic -Werror)
elseif (MSVC)
    target_compile_options(Lion PRIVATE /W4 /WX)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(Lion PRIVATE -O3)
    elseif(MSVC)
        target_compile_options(Lion PRIVATE /O2)
    endif()
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(Lion PRIVATE -g -fsanitize=address)
        target_link_libraries(Lion PRIVATE -fsanitize=address)
    elseif(MSVC)
        target_compile_options(Lion PRIVATE /Zi /RTC1)
    endif()
endif()