#include "Poesie.h"
using namespace std;
#include <iostream>

Poesie::Poesie()
{
	indicateur = "";
	this->type = POESIE;
    code = 0;
}

Poesie::Poesie(const string& auteur, const string& titre, const string& editeur, const string& isbn, const string& public_vise, const string& indic) :Livre(auteur, titre, editeur, isbn, public_vise)
{
	indicateur = indic; 
	this->type = POESIE;
    code = 0;
}
const string& Poesie::getIndicateur() const
{
	return indicateur;
}
void Poesie::setIndicateur(const string& indic)
{
	indicateur = indic;
}

void Poesie::affiche()
{
	Livre::affiche();
	cout << "Ce recueil de poséie contient des " << indicateur << endl;
}
