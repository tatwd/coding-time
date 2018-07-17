cmake_minimum_required(VERSION 2.8)

# set(CMAKE_MAKE_PROGRAM "C:/MinGW/bin/mingw32-make.exe")
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

project(Coding-Time)

aux_source_directory(. DIR_SRCS)

add_executable(app ${DIR_SRCS})
