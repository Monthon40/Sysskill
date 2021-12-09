# cmake_minimum_required(VERSION <specify CMake version here>)
project(Inclass6)

set(CMAKE_CXX_STANDARD 14)

add_executable(Inclass6
        .idea/.gitignore
        .idea/Inclass6.iml
        .idea/modules.xml
        .idea/workspace.xml
        arg.c
        c2f.c
        "input .txt"
        pretty.c prettyy.cpp prettyy.h)
