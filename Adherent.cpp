//
// Created by Massi on 09/01/2024.
//

#include "Adherent.h"

int Adherent::nbAdherent = 0;

Adherent::Adherent(string nom, string prenom, string adresse, Bibliotheque* bibliotheque) {
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->idAdherent = nbAdherent++; // on donne un id a l'adherent et on incremente le nombre d'adherent
    this->bibliotheque = bibliotheque;
}

Adherent::~Adherent() = default;

const string& Adherent::getNom() const {
    return nom;
}

void Adherent::setNom(const string& nom) {
    Adherent::nom = nom;
}

const string& Adherent::getPrenom() const {
    return prenom;
}

void Adherent::setPrenom(const string& prenom) {
    Adherent::prenom = prenom;
}

const string& Adherent::getAdresse() const {
    return adresse;
}

void Adherent::setAdresse(const string& adresse) {
    Adherent::adresse = adresse;
}

const int& Adherent::getIdAdherent() const {
    return idAdherent;
}

void Adherent::emprunterLivre(int codeLivre) {
    int id = bibliotheque->getIndiceLivre(codeLivre);
    if (bibliotheque->getLivre(id).getEtat() == false) {
        //vérifier si il peut emprunter(try/catch)
        // ajouter livre dans livres
        bibliotheque->setLivre(id)->setEtat(true);
    }
}

void Adherent::rendreLivre(Livre* livre) 
{
    //trouver livre
    //changer son état
    // enlever livre de livres
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
