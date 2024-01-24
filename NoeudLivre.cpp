#include "NoeudLivre.h"

NoeudLivre::NoeudLivre(const Livre& l)
{
    livre = l;
    suivant = nullptr;
}

NoeudLivre::NoeudLivre(const Livre& l, NoeudLivre *next)
{
    livre = l;
    suivant = next;
}

NoeudLivre* NoeudLivre::getSuivant()
{
    return suivant;
}

void NoeudLivre::setSuivant(NoeudLivre *next)
{
    suivant = next;
}

Livre NoeudLivre::getLivre()
{
    return livre;
}
