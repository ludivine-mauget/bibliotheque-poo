//
// Created by Massi on 09/01/2024.
//

#include "Adherent.h"

Adherent::Adherent(string nom, string prenom, string adresse, Bibliotheque *bibliotheque) {
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->idAdherent = nbAdherent++; // on donne un id a l'adherent et on incremente le nombre d'adherent
    this->bibliotheque = bibliotheque;
}

const string &Adherent::getNom() const {
    return nom;
}

void Adherent::setNom(const string &nom) {
    Adherent::nom = nom;
}

const string &Adherent::getPrenom() const {
    return prenom;
}

void Adherent::setPrenom(const string &prenom) {
    Adherent::prenom = prenom;
}

const string &Adherent::getAdresse() const {
    return adresse;
}

void Adherent::setAdresse(const string &adresse) {
    Adherent::adresse = adresse;
}

const int &Adherent::getIdAdherent() const {
    return idAdherent;
}

void Adherent::emprunterLivre(string codeLivre) {
    // TODO : emprunter un livre
}

void Adherent::rendreLivre(Livre *livre) {
    // TODO : rendre un livre
}

void Adherent::afficheAdherent() {
    cout << "Nom : " << nom << endl;
    cout << "Prénom : " << prenom << endl;
    cout << "Adresse : " << adresse << endl;
    cout << "Id : " << idAdherent << endl;
    cout << "Bibliothèque : " << bibliotheque->getNom() << endl;
    cout << "Livres empruntés : " << endl;
    for (auto livre : livresEmpruntes) {
        cout << livre->getTitre() << endl;
    }
}
