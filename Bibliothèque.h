#pragma once
#include <iostream>
#include "adherent.h"
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
