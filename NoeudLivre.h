#ifndef BIBLIOTHEQUE_POO_NOEUDLIVRE_H
#define BIBLIOTHEQUE_POO_NOEUDLIVRE_H

#include "Livre.h"

class NoeudLivre
{
friend class ListeLivre;

private:
	Livre livre;
	NoeudLivre *suivant;

public :
	NoeudLivre(const Livre& livre);
    NoeudLivre(Livre livre, NoeudLivre *suivant);
    NoeudLivre* getSuivant();
    void setSuivant(NoeudLivre *suivant);
    Livre getLivre();
};

#endif //BIBLIOTHEQUE_POO_NOEUDLIVRE_H