#pragma once

#ifndef BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H

#include <iostream>
#include "Adherent.h"
#include "Livre.h"
using namespace std;

class Bibliotheque
{
private:
	string nom;
	string adresse;
	string code;
	Livre* livres;
public:
	Bibliotheque();
	Bibliotheque(string n, string a, string c);
	~Bibliotheque();
	void DemanderLivre(string isbn);
	void AcheterNouveauLivre(Livre l);
	void SupprimerLivre(string codeLivre);
	void RendreLivrePretes();
};

#endif //BIBLIOTHEQUE_POO_BIBLIOTHEQUE_H