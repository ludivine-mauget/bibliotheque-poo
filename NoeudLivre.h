#ifndef BIBLIOTHEQUE_POO_NOEUDLIVRE_H
#define BIBLIOTHEQUE_POO_NOEUDLIVRE_H

#include "Livre.h"

class NoeudLivre
{
private:
	Livre livre;
	NoeudLivre *suivant;

public :
	explicit NoeudLivre(const Livre& l);
    NoeudLivre(Livre l, NoeudLivre *next);
    NoeudLivre* getSuivant();
    void setSuivant(NoeudLivre *next);
    Livre getLivre();
};

#endif //BIBLIOTHEQUE_POO_NOEUDLIVRE_H