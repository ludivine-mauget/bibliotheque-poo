//
// Created by Massif on 08/01/2024.
//

#include "Bibliotheque.h"
#include <iostream>
#include <string>

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
    cout << "Liste des livres empruntés : " << endl;
    afficheLivresEmpruntes();
}

void Bibliotheque::afficheAdherents() {
    for (auto adherent : adherents) {
        cout << adherent->getNom() << endl;
    }
}

void Bibliotheque::afficheLivres() {
    for (auto livre : livres) {
        cout << livre->getTitre() << endl;
    }
}

void Bibliotheque::afficheLivres(string categorie) {
    for (auto livre : livres) {
        if (livre->getPublicVise() == categorie) { // TODO: catégorie soit public visé soit type de livre (roman, album, etc.)
            cout << livre->getTitre() << endl;
        }
    }
}

void Bibliotheque::afficheLivresEmpruntes() {
    for (auto livre : livresEmpruntes) {
        cout << livre->getTitre() << endl;
    }
}

void Bibliotheque::rendreLivre(string isbn) {
    // TODO : rendre le livre grâce au code
}

void Bibliotheque::acheterLivre(const Livre& livre) {
    livres.push_back((Livre*)&livre);
}

void Bibliotheque::supprimerLivre(const Livre& livre) {
    int indice = getIndiceLivre(livre.getCode());
    livres.erase(livres.begin() + indice);
}


int Bibliotheque::getIndiceLivre(int code) {
    int i = 0;
    try {
    for (auto c : livres) {
        if (c->getCode() == code) {
            return i;
        }
        i++;
        if (i == livres.size()) {
            throw runtime_error("Le livre n'existe pas");
        }
    }
    } catch (runtime_error &e) {
        cerr << "Exception trouvée : " << e.what() << endl;
    }
    return -1;
}

void Bibliotheque::ajouterAdherent(const Adherent& adherent) {
    adherents.push_back((Adherent*)&adherent);
}

void Bibliotheque::supprimerAdherent(const Adherent& adherent) {
    int i = 0;
    for (auto a : adherents) {
        if (a->getIdAdherent() == adherent.getIdAdherent()) {
            adherents.erase(adherents.begin() + i);
            a->~Adherent();
        }
        i++;
    }
}

string Bibliotheque::getNom(){
    return nom;
}

void Bibliotheque::setNom(const string &n) {
    this->nom = n;
}

int Bibliotheque::getNbLivresMax() {
    return nbLivresMax;
}

void Bibliotheque::setNbLivresMax(int nbLivresMax) {
    this->nbLivresMax = nbLivresMax;
}

Livre Bibliotheque::getLivre(int indice) {
    return *livres[indice];
}

