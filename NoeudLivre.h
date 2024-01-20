#pragma once
#include "Livre.h"

class NoeudLivre
{
private:
	Livre livre;
	NoeudLivre*suivant;
public:
	explicit NoeudLivre(const Livre& livre);
    NoeudLivre(Livre l, NoeudLivre* next);
	Livre getLivre();
	NoeudLivre* getSuivant();
	void setLivre(Livre l);
	void setSuivant(NoeudLivre* next);
};

