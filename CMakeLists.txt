cmake_minimum_required(VERSION 3.8)
project(oop_task1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_COMPILE_FEATURES Wall Wpedantic Werror)

set(SOURCE_FILES main.cpp)
add_executable(oop_task1 ${SOURCE_FILES})