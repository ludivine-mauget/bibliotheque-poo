#pragma once
#include <iostream>
#include "Adhérent.h"
#include "Livre.h"
using namespace std;

class Bibliothèque
{
private:
	string nom;
	string adresse;
	string code;
	Livre* livres;
public:
	Bibliothèque();
	Bibliothèque(string n, string a, string c);
	~Bibliothèque();
	void DemanderLivre(string isbn);
	void AcheterNouveauLivre(Livre l);
	void SupprimerLivre(string codeLivre);
	void RendreLivrePretes();
};
