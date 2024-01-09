#include "Emprunteur.h"

Emprunteur::Emprunteur()
{
    biblio = nullptr;
    adherent = nullptr;
}

const Bibliotheque* Emprunteur::getBiblio()
{
    return biblio;
}

const Adherent* Emprunteur::getAdherent()
{
    return adherent;
}

void Emprunteur::setBiblio(Bibliotheque* bibliotheque)
{
    this->biblio = bibliotheque;
}

void Emprunteur::setAdherent(Adherent *adherent)
{
    this->adherent = adherent;
}
