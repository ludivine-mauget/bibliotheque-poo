//
// Created by Ludivine Mauget on 09/01/2024.
//

#include "BD.h"

BD::BD(int code, const string &auteur, const string &titre, const string &editeur, const string &isbn,
       const string &public_vise, const string &dessinateur) : Livre(code, auteur, titre, editeur, isbn, public_vise) {
    this->dessinateur = dessinateur
}

BD::BD() : Livre() {
    dessinateur = "";
}

BD::BD(const string &dessinateur) : Livre() {
    this->dessinateur = dessinateur;
}

const string &BD::getDessinateur() const {
    return dessinateur;
}

void BD::setDessinateur(const string &dessinateur) {
    this->dessinateur = dessinateur;
}

void BD::affiche() {
    Livre::affiche();
    cout << "Dessinateur : " << dessinateur << endl;
}



