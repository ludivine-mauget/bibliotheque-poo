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

void Bibliotheque::rendreLivre(string isbn) {
    // TODO : rendre le livre grâce au code
}

void Bibliotheque::acheterLivre(const Livre& livre) {
    livres.push_back((Livre*)&livre);
}

void Bibliotheque::supprimerLivre(const Livre& livre) {

}

void Bibliotheque::ajouterAdherent(const Adherent& adherent) {
    adherents.push_back((Adherent*)&adherent);
}

void Bibliotheque::supprimerAdherent(Adherent adherent) {
    //TODO : update notation vecteur
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

