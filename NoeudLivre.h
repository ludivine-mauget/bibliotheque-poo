#pragma once
#include "Livre.h"
#include "ListeLivre.h"

class NoeudLivre
{
friend class ListeLivre;

private:
	Livre livre;
	NoeudLivre* suivant;

	NoeudLivre(Livre livre) { this->livre = livre; }
	NoeudLivre(Livre livre, NoeudLivre* noeud) { this->livre = livre; suivant = noeud; }	
};

