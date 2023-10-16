cmake_minimum_required(VERSION 3.23)
project(ed2023)

set(CMAKE_C_STANDARD 11)

add_executable(ed2023
        TP1/src/stack.cpp
        TP1/src/main.cpp
        TP1/include/expression.h
        TP1/include/expression.h
        TP1/src/expression.cpp
        TP1/src/tree.cpp
        TP1/include/tree.h
        TP1/src/satisfiability.cpp
        TP1/include/satisfiability.h
)
