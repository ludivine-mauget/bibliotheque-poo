#include "Poesie.h"
using namespace std;
#include <iostream>

Poesie::Poesie(Indic i)
{
    indicateur = i;
    this->type = POESIE;
}

void Poesie::affiche()
{
	Livre::affiche();
    cout << "Indicateur : " << indicateur << endl;
}
