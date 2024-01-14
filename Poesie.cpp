#include "Poesie.h"
using namespace std;
#include <iostream>

Poesie::Poesie()
{
	indicateur = "";
	this->type = POESIE;
}

Poesie::Poesie(int code, const string& auteur, const string& titre, const string& editeur, const string& isbn, const string& public_vise, const string& indic) :Livre(code, auteur, titre, editeur, isbn, public_vise) 
{
	indicateur = indic; 
	this->type = POESIE;
}
const string& Poesie::getIndicateur() const
{
	return indicateur;
}
void Poesie::setIndicateur(const string& indic)
{
	indicateur = indic;
}

void Poesie::Affiche()
{
	Livre::affiche();
	cout << "Ce recueil de poséie contient des " << indicateur << endl;
}
