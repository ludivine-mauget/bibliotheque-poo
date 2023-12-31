#pragma once

#ifndef BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H

#include <iostream>
#include <set>
#include <string>
#include "Adherent.h"
#include "Livre.h"
using namespace std;

class Bibliotheque
{
private:
	string nom;
	set<Adherent> adherents;
    set<Livre> livres;
    int nbLivresMax;
public:
	Bibliotheque();
    Bibliotheque(string nom, int nbLivresMax);
    void afficheBibliotheque();
    void afficheAdherents();
    void afficheLivres();
    void afficheLivres(string categorie);
    void preterLivre(Bibliotheque bibliotheque, string isbn);
    void rendreLivre(string isbn);
    void acheterLivre(Livre livre);
    void supprimerLivre(Livre livre);
    void ajouterAdherent(Adherent adherent);
    void supprimerAdherent(Adherent adherent);
    void setNom(string nom);
    string getNom();
    void setNbLivresMax(int nbLivresMax);
    int getNbLivresMax();
    void setAdherents(set<Adherent> adherents);
    set<Adherent> getAdherents();
    Livre getLivre(string isbn);
};

#endif //BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H