#pragma once

#include "Bibliotheque.h"
#include "Adherent.h"

class Emprunteur
{
private:
	Bibliotheque biblio;
	Adherent adherent;
public:
	Emprunteur();
	const Bibliotheque &getBiblio();
	const Adherent &getAdherent();
	void setBiblio(const Bibliotheque &bibliotheque);
	void setAdherent(const Adherent &adherent);
};

