cmake_minimum_required(VERSION 3.23)
project(bibliotheque-poo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bibliotheque-poo
        Adherent.h
        Album.cpp
        Album.h
        Theatre.h
        Poesie.cpp
        Poesie.h
        Roman.h
        BD.cpp
        BD.h
        Bibliotheque.cpp
        Bibliotheque.h
        Livre.cpp
        Livre.h
        Roman.cpp
        Theatre.cpp)

