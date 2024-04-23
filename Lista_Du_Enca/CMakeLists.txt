cmake_minimum_required(VERSION 3.28)
project(Lista_Du_Enca C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lista_Du_Enca
        Lista_D_Enca.c
        Lista_D_Enca.h
        main.c)
