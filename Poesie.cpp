#include "Poesie.h"
using namespace std;
#include <iostream>

Poésie::Poésie(const Poésie& poésie)
{
  //oui
}

void Poésie::Affiche()
{
	if (indicateur == vers) {
		affiche();
		cout << "C'est un vers" << endl;
	}
	else if (indicateur == prose) {
		affiche();
		cout << "C'est une prose" << endl;
	}
	else {
		affiche();
		cout << "C'est une prose et un vers" << endl;
	}
}
