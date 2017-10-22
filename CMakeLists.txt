cmake_minimum_required(VERSION 3.8)
project(compilador)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Lexico.cpp Lexico.h structs.h Sintatico.cpp Sintatico.h)
add_executable(compilador ${SOURCE_FILES})