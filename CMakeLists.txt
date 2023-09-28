cmake_minimum_required(VERSION 3.23)
project(ed2023 C)

set(CMAKE_C_STANDARD 11)

add_executable(ed2023
        ap02/analisamem/src/pilhaindexada.c
        ap02/analisamem/include/msgassert.h
        ap02/analisamem/include/pilhaindexada.h)
