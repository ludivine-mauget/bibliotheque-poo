//
// Created by Massi on 09/01/2024.
//

#include "Theatre.h"
#include <iostream>

using namespace std;

Theatre::Theatre(const string &auteur, const string &titre, const string &editeur, const string &isbn,
                 const string &public_vise, const string &genre) : Livre(auteur, titre, editeur, isbn,
                                                                         public_vise), genre(genre) {
    this->type = THEATRE;
    this->genre = genre;
    code = 0;
}

Theatre::Theatre(const Theatre *r) {
    this->code = r->code;
    this->auteur = r->auteur;
    this->titre = r->titre;
    this->editeur = r->editeur;
    this->ISBN = r->ISBN;
    this->publicVise = r->publicVise;
    this->genre = r->genre;
    this->type = THEATRE;
}

// TODO : Probleme avec affiche
void Theatre::affiche() {
    Livre::affiche();
    cout << "Genre : " << genre << endl;
}

const string &Theatre::getGenre() const {
    return genre;
}

void Theatre::setGenre(const string &g) {
    genre = g;
}



