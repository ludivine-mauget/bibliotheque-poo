//
// Created by Massif on 09/01/2024.
//

#include "Roman.h"
#include <iostream>
#include <string>

using namespace std;

Roman::Roman(const string &auteur, const string &titre, const string &editeur, const string &isbn,
             const string &public_vise, const string &genre)
        : Livre(auteur, titre, editeur, isbn, public_vise) {
    this->genre = genre;
    this->type = ROMAN;
    code = 0;
}

Roman::Roman(const Roman *r) {
    this->code = r->code;
    this->auteur = r->auteur;
    this->titre = r->titre;
    this->editeur = r->editeur;
    this->ISBN = r->ISBN;
    this->publicVise = r->publicVise;
    this->genre = r->genre;
    this->type = ROMAN;
}

// Probleme avec affiche
void Roman::affiche() {
    Livre::affiche();
    cout << "Genre : " << genre << endl;
}

const string &Roman::getGenre() const {
    return genre;
}

void Roman::setGenre(const string &g) {
    genre = g;
}

