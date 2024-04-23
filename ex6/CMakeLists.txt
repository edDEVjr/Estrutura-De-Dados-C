cmake_minimum_required(VERSION 3.28)
project(ex6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex6
        .idea/.gitignore
        .idea/ex6.iml
        .idea/modules.xml
        .idea/workspace.xml
        cliente.c
        cliente.h
        clientes.txt
        main.c)
