//
// Created by Massif on 08/01/2024.
//

#include "Bibliotheque.h"


#include <iostream>
#include <string>
#include <set>

using namespace std;

Bibliotheque::Bibliotheque() {
    nom = "";
    nbLivresMax = 0;
}

Bibliotheque::Bibliotheque(string nom, int nbLivresMax){
    this->nom = nom;
    this->nbLivresMax = nbLivresMax;
}

void Bibliotheque::afficheBibliotheque() {
    cout << "Nom de la bibliothèque : " << nom << endl;
    cout << "Nombre de livres maximum : " << nbLivresMax << endl;
    cout << "Liste des adhérents : " << endl;
    afficheAdherents();
    cout << "Liste des livres : " << endl;
    afficheLivres();
}

void Bibliotheque::afficheAdherents() {
    for (auto adherent : adherents) {
        cout << adherent.getNom() << endl;
    }
}

void Bibliotheque::afficheLivres() {
    for (auto livre : livres) {
        cout << livre.getTitre() << endl;
    }
}

void Bibliotheque::afficheLivres(string categorie) {
    for (auto livre : livres) {
        if (livre.getPublicVise() == categorie) { // TODO: catégorie soit public visé soit type de livre (roman, album, etc.)
            cout << livre.getTitre() << endl;
        }
    }
}



void Bibliotheque::rendreLivre(string isbn) {
    ;// TODO : rendre le livre grâce au code
}

void Bibliotheque::acheterLivre(Livre livre) {
    livres.insert(livre); // TODO : est-ce qu'utiliser un set est la bonne solution ?
}

void Bibliotheque::supprimerLivre(Livre livre) {
    livres.erase(livre);
}

void Bibliotheque::ajouterAdherent(Adherent adherent) {
    adherents.insert(adherent);
}

void Bibliotheque::supprimerAdherent(Adherent adherent) {
    adherents.erase(adherent);
}

const string &Bibliotheque::getNom() const {
    return nom;
}

void Bibliotheque::setNom(const string &nom) {
    this->nom = nom;
}

int Bibliotheque::getNbLivresMax() const {
    return nbLivresMax;
}

void Bibliotheque::setNbLivresMax(int nbLivresMax) {
    this->nbLivresMax = nbLivresMax;
}

const set<Adherent> &Bibliotheque::getAdherents() const {
    return adherents;
}

void Bibliotheque::setAdherents(const set<Adherent> &adherents) {
    this->adherents = adherents;
}

const set<Livre> &Bibliotheque::getLivres() const {
    return livres;
}

void Bibliotheque::setLivres(const set<Livre> &livres) {
    this->livres = livres;
}

Livre Bibliotheque::getLivre(string isbn) {
    for (auto livre : livres) {
        if (livre.getIsbn() == isbn) {
            return livre;
        }
    }
}




