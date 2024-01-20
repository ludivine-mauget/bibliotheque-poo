
//
// Created by Massif on 08/01/2024.
//

#include "Livre.h"


using namespace std;

Livre::Livre(int code, const string& auteur, const string& titre, const string& editeur, const string& isbn,
    const string& public_vise) : code(code), auteur(auteur), titre(titre), editeur(editeur), ISBN(isbn),
    publicVise(public_vise) {
    etat = false;
}

Livre::Livre() {
    
    type = LIVRE;
    etat = false;
}

Livre::~Livre() = default;

Livre::Livre(const Livre& livre)
{
    type = livre.type;
    code = livre.code;
    auteur = livre.auteur;
    titre = livre.titre;
    editeur = livre.editeur;
    ISBN = livre.ISBN;
    publicVise = livre.publicVise;
    etat = livre.etat;
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

const bool& Livre::getEtat() const
{
    return etat;
}

void Livre::setEtat(const bool& etat)
{
    this->etat = etat;
}

void Livre::affiche() {
    cout << "Code : " << code << endl;
    cout << "Auteur : " << auteur << endl;
    cout << "Titre : " << titre << endl;
    cout << "Editeur : " << editeur << endl;
    cout << "ISBN : " << ISBN << endl;
    cout << "Public visé : " << publicVise << endl;
}
