//
// Created by Massi on 09/01/2024.
//

#ifndef BIBLIOTHEQUE_POO_ADHERENT_H
#define BIBLIOTHEQUE_POO_ADHERENT_H

#include <iostream>
#include "NoeudLivre.h"
#include <string>

class Bibliotheque;

using namespace std;

class Adherent {
private:
    NoeudLivre* listeLivre; // premier livre du noeud
    string nom;
    string prenom;
    string adresse;
    int idAdherent;
    Bibliotheque *bibliotheque;
    int nbMaxEmprunt;
public:
    Adherent(string nom, string prenom, string adresse, Bibliotheque* bibliotheque);
    ~Adherent();
    const string& getNom() const;
    void setNom(const string& nom);
    const string& getPrenom() const;
    void setPrenom(const string& prenom);
    const string& getAdresse() const;
    void setAdresse(const string& adresse);
    int getNbEmprunts();
    const int& getIdAdherent() const;
    void setIdAdherent(const int& id);
    const int& getMaxEmprunt() const;

    void ajouteLivre(Livre livre);
    void supprimeLivre(Livre livre);

    void emprunterLivre(int codeLivre);
    void rendreLivre(int code);
    void afficheAdherent();
};


#endif //BIBLIOTHEQUE_POO_ADHERENT_H
