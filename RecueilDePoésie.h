#pragma once
#include "Livre.h"
using namespace std;

enum Indic{vers,prose,both};

class RecueilDePoesie :
    public Livre
{
private:
    Indic indicateur;
};
