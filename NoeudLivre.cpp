#include "NoeudLivre.h"

NoeudLivre::NoeudLivre(const Livre& livre)
{
    this->livre = livre;
    suivant = NULL;
}

NoeudLivre::NoeudLivre(Livre livre, NoeudLivre *suivant)
{
    this->livre = livre;
    this->suivant = suivant;
}

NoeudLivre* NoeudLivre::getSuivant()
{
    return suivant;
}

void NoeudLivre::setSuivant(NoeudLivre *suivant)
{
    this->suivant = suivant;
}

Livre NoeudLivre::getLivre()
{
    return livre;
}
