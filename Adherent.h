//
// Created by Massi on 09/01/2024.
//

#ifndef BIBLIOTHEQUE_POO_ADHERENT_H
#define BIBLIOTHEQUE_POO_ADHERENT_H

#include <iostream>
#include "Bibliotheque.h"
#include "Livre.h"
#include <string>

using namespace std;

class Bibliotheque; // peut etre que ça va casser apres
class Livre;

class Adherent {
private:

    string nom;
    string prenom;
    string adresse;
    int idAdherent;
    Bibliotheque *bibliotheque;
    vector<Livre*> livresEmpruntes;
public:
    static int nbAdherent;

    Adherent(string nom, string prenom, string adresse, Bibliotheque *bibliotheque);
    ~Adherent();
    const string &getNom() const;
    void setNom(const string &nom);
    const string &getPrenom() const;
    void setPrenom(const string &prenom);
    const string &getAdresse() const;
    void setAdresse(const string &adresse);
    const int &getIdAdherent() const;

    void emprunterLivre(string codeLivre);
    void rendreLivre(Livre *livre);
    void afficheAdherent();


};


#endif //BIBLIOTHEQUE_POO_ADHERENT_H
