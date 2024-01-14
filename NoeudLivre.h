#pragma once
#include "Livre.h"

class NoeudLivre
{
private:
	Livre livre;
	NoeudLivre* suivant;
public:
	NoeudLivre();
	NoeudLivre(Livre livre);
	NoeudLivre(Livre livre, NoeudLivre* next);
	const Livre& getLivre() const;
	NoeudLivre& getSuivant();
	void setLivre(const Livre& livre);
	void setSuivant(NoeudLivre* suivant);
};

