//
// Created by Massif on 08/01/2024.
//

#include "Livre.h"


using namespace std;

Livre::Livre(int code, const string& auteur, const string& titre, const string& editeur, const string& isbn,
    const string& public_vise) : code(code), auteur(auteur), titre(titre), editeur(editeur), ISBN(isbn),
    publicVise(public_vise){
}

Livre::Livre() {
    emprunte_par=nullptr;
    type = LIVRE;
}

int Livre::getCode() const {
    return code;
}

void Livre::setCode(int c) {
    code = c;
}

const string& Livre::getAuteur() const {
    return auteur;
}

void Livre::setAuteur(const string& a) {
    auteur = a;
}

const string& Livre::getTitre() const {
    return titre;
}

void Livre::setTitre(const string& t) {
    titre = t;
}

const string& Livre::getEditeur() const {
    return editeur;
}

void Livre::setEditeur(const string& e) {
    editeur = e;
}

const string& Livre::getIsbn() const {
    return ISBN;
}

void Livre::setIsbn(const string& i) {
    ISBN = i;
}

const string& Livre::getPublicVise() const {
    return publicVise;
}

void Livre::setPublicVise(const string& p) {
    publicVise = p;
}

void Livre::affiche() {
    cout << "Code : " << code << endl;
    cout << "Auteur : " << auteur << endl;
    cout << "Titre : " << titre << endl;
    cout << "Editeur : " << editeur << endl;
    cout << "ISBN : " << ISBN << endl;
    cout << "Public visé : " << publicVise << endl;
    if (emprunte_par->getAdherent() != nullptr) {
        cout << "Emprunté par : " << emprunte_par->getAdherent()->getNom() << " " << emprunte_par->getAdherent()->getPrenom() << endl;
    }
}

const Emprunteur Livre::getEmprunteur()
{
    return emprunte_par;
}

