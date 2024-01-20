#include "NoeudLivre.h"

NoeudLivre::NoeudLivre(const Livre& livre)
{
    this->livre = livre;
    this->suivant = nullptr;
}
NoeudLivre::NoeudLivre(Livre l, NoeudLivre* next)
{
    livre = l;
    suivant = next;
}

Livre NoeudLivre::getLivre()
{
    return livre;
}

NoeudLivre* NoeudLivre::getSuivant()
{
    return suivant;
}

void NoeudLivre::setLivre(Livre l)
{
    this->livre = l;
}

void NoeudLivre::setSuivant(NoeudLivre* next)
{
    suivant = next;
}
