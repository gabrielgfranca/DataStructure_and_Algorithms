cmake_minimum_required(VERSION 3.31)
project(DataStructure_and_Algorithms C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructure_and_Algorithms main.c
        DataStructures/arrays.c
        DataStructures/stack.c)
