cmake_minimum_required(VERSION 3.5)
project(shell)

set(CMAKE_CXX_STANDARD 14)

add_executable(shell main.cpp Shell.cpp Shell.h Commands.cpp Commands.h)