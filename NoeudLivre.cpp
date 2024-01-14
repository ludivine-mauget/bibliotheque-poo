#include "NoeudLivre.h"

NoeudLivre::NoeudLivre()
{
	livre = NULL;
	suivant = nullptr;
}

NoeudLivre::NoeudLivre(Livre livre)
{
	this->livre = livre;
	suivant = nullptr;
}

NoeudLivre::NoeudLivre(Livre livre, NoeudLivre* next)
{
	this->livre = livre;
	suivant = next;
}

const Livre& NoeudLivre::getLivre() const
{
	return livre;
}

NoeudLivre& NoeudLivre::getSuivant()
{
	return *suivant;
}

void NoeudLivre::setLivre(const Livre& livre)
{
	this->livre = livre;
}

void NoeudLivre::setSuivant(NoeudLivre* suivant)
{
	this->suivant = suivant;
}
