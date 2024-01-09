#include "Emprunteur.h"

Emprunteur::Emprunteur()
{
    biblio = Bibliotheque();
    adherent = Adherent();
}

const Bibliotheque &Emprunteur::getBiblio()
{
    return biblio;
}

const Adherent &Emprunteur::getAdherent()
{
    return adherent;
}

void Emprunteur::setBiblio(const Bibliotheque &bibliotheque)
{
    biblio = bibliotheque;
}

void Emprunteur::setAdherent(const Adherent& adherent)
{
    this->adherent = adherent;
}
