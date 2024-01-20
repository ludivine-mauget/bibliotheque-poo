#include "NoeudLivre.h"

NoeudLivre::NoeudLivre(const Livre& livre)
{
    this->livre = livre;
    this->suivant = nullptr;
}
NoeudLivre::NoeudLivre(Livre l, NoeudLivre* next)
{
    this->livre = l;
    this->suivant = next;
}

Livre NoeudLivre::getLivre()
{
    return livre;
}

NoeudLivre* NoeudLivre::getSuivant()
{
    return suivant;
}

void NoeudLivre::setLivre(Livre livre)
{
    this->livre = livre;
}

void NoeudLivre::setSuivant(NoeudLivre* next)
{
    this->suivant = next;
}
