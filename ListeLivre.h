#pragma once
#include "Adherent.h"
#include"NoeudLivre.h"

class ListeLivre
{
private:
	NoeudLivre* tete;
	int nbLivre;
public:
	ListeLivre();
	ListeLivre(const ListeLivre& liste);
	~ListeLivre();
	
	Livre getLivre(int position) const ;

	void AddLivre(Livre newLivre,Adherent adherent);
	void RemoveLivre(Livre livre);
	int size() const { return nbLivre; }
	void affiche();
};

