#include "NoeudLivre.h"

NoeudLivre::NoeudLivre()
{
	suivant = nullptr;
}

NoeudLivre::NoeudLivre(const Livre& livre)
{
	this->livre = livre;
	suivant = nullptr;
}

Livre NoeudLivre::getLivre()
{
	return livre;
}

NoeudLivre& NoeudLivre::getSuivant()
{
	return *suivant;
}

void NoeudLivre::setLivre(Livre& livre)
{
	this->livre = livre;
}

void NoeudLivre::setSuivant(NoeudLivre* suivant)
{
	this->suivant = suivant;
}
