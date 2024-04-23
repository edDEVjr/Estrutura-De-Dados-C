cmake_minimum_required(VERSION 3.28)
project(ListaEnca C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ListaEnca
        Lista_Enc.c
        Lista_Enc.h
        main.c
        ex29.c
        ex29.h
        mainEx29.c)
