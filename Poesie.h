#pragma once
#include "Livre.h"
using namespace std;

enum Indic { VERS, PROSE, BOTH };

class Poesie : public Livre
{
private:
    Indic indicateur;
public:
    Poesie(Indic);
    void affiche();
};

