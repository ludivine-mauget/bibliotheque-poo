#ifndef BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H

#include <iostream>
#include <vector>
#include <string>
#include "Adherent.h"
using namespace std;

class Bibliotheque
{
private:
	string nom;
	vector<Adherent*> adherents;
    vector<Livre*> livres;
    vector<Livre*> livresEmpruntes;
    int nbLivresMax;
    int numAdherent;
    int idLivre;
public:
    Bibliotheque(string nom, int nbLivresMax);
    void afficheBibliotheque();
    void afficheAdherents();
    void afficheLivres();
    void afficheLivres(const string& categorie);
    void emprunterLivre(const string& isbn, Bibliotheque bibliotheque);
    void rendreLivre(string isbn, Bibliotheque bibliotheque);
    void acheterLivre(const Livre& livre);
    void supprimerLivre(const Livre& livre);
    void ajouterAdherent(Adherent adherent);
    void supprimerAdherent(const Adherent& adherent);
    void setNom(const string &nom);
    string getNom();
    void setNbLivresMax(int nbLivresMax);
    int getNbLivresMax();
    vector<Adherent*> getAdherents();
    template<typename T>
    int getIndiceLivre(T arg);
    int getIndiceEmprunt(const string& isbn);
    void afficheLivresEmpruntes();
    Livre getLivre(int indice);
};

#endif // BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H