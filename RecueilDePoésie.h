#pragma once
#include "Livre.h"
using namespace std;

enum Indic{vers,prose,both};

class RecueilDePoésie :
    public Livre
{
private:
    Indic indicateur;
};
