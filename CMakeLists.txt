cmake_minimum_required(VERSION 3.23)
project(bibliotheque_poo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bibliotheque_poo
        BD.cpp
        BD.h
        Bibliotheque.cpp
        Bibliotheque.h
        Livre.cpp
        Livre.h)
