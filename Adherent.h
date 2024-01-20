//
// Created by Massi on 09/01/2024.
//

#ifndef BIBLIOTHEQUE_POO_ADHERENT_H
#define BIBLIOTHEQUE_POO_ADHERENT_H

#include <iostream>
#include "Bibliotheque.h"
#include <string>
#include "NoeudLivre.h"

using namespace std;

class Adherent {
private:
    string nom;
    string prenom;
    string adresse;
    int idAdherent;
    Bibliotheque *bibliotheque;
    NoeudLivre *livres; //liste chaînée des livres empruntés
    int nbEmprunt;
    int nbMaxEmprunt;
public:
    static int nbAdherent;
    Adherent(string nom, string prenom, string adresse, Bibliotheque* bibliothequen, int maxEmprunt);
    ~Adherent();
    const string& getNom() const;
    void setNom(const string& nom);
    const string& getPrenom() const;
    void setPrenom(const string& prenom);
    const string& getAdresse() const;
    void setAdresse(const string& adresse);
    const int& getIdAdherent() const;

    void emprunterLivre(int codeLivre);
    void rendreLivre(Livre* livre);
    void afficheAdherent();
};


#endif //BIBLIOTHEQUE_POO_ADHERENT_H
