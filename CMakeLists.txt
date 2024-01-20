cmake_minimum_required(VERSION 3.23)
project(bibliotheque-poo)

set(CMAKE_CXX_STANDARD 17)

# compile utf8
include_directories(.)

add_executable(bibliotheque-poo
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
        Theatre.cpp
        main.cpp
        Adherent.cpp
        Adherent.h
        Album.h
        Album.cpp
        NoeudLivre.h
        NoeudLivre.cpp
)

