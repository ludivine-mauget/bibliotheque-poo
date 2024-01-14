#ifndef BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H

#include <iostream>
#include <vector>
#include <string>
#include "Livre.h"
#include "Adherent.h"
using namespace std;

class Adherent;

class Bibliotheque
{
private:
	string nom;
	vector<Adherent*> adherents;
    vector<Livre*> livres;
    vector<Livre*> livresEmpruntes;
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
    void acheterLivre(const Livre& livre);
    void supprimerLivre(const Livre& livre);
    void ajouterAdherent(const Adherent& adherent);
    void supprimerAdherent(const Adherent& adherent);
    void setNom(const string &nom);
    string getNom();
    void setNbLivresMax(int nbLivresMax);
    int getNbLivresMax();
    vector<Adherent*> getAdherents();
    Livre getLivre(string isbn);
    int getIndiceLivre(int code);
    void afficheLivresEmpruntes();
    Livre getLivre(int indice);
};

#endif // BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H