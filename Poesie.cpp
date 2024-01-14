#include "Poesie.h"

Poesie::Poesie(Indic i)
{
    indicateur = i;
}

void Poesie::affiche()
{
	Livre::affiche();
    cout << "Indicateur : " << indicateur << endl;
}
