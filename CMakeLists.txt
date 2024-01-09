cmake_minimum_required(VERSION 3.26)
project(bibliotheque_poo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bibliotheque_poo
        Adherent.h
        Album.cpp
        Album.h
        BandeDessinee.h
        Bibliotheque.h
        Livre.h
        PieceDeTheatre.h
        Poesie.cpp
        Poesie.h
        RecueilDePoesie.h
        Roman.h)
