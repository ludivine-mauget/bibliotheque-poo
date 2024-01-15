#pragma once
#include "Livre.h"

class NoeudLivre
{
private:
	Livre livre;
	NoeudLivre* suivant;
public:
	NoeudLivre();
	NoeudLivre(const Livre& livre);
	Livre getLivre();
	NoeudLivre& getSuivant();
	void setLivre(Livre& livre);
	void setSuivant(NoeudLivre* suivant);
};

