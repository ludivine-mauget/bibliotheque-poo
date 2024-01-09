#pragma once
#include "Livre.h"
using namespace std;

enum Indic { vers, prose, both };

class Poesie :
    public Livre
{
private:
    Indic indicateur;
public:
    Poesie():Livre() {};
    Poesie(int code, const string& auteur, const string& titre, const string& editeur, const string& isbn, const string& public_vise, const Indic& indic) :Livre(code, auteur, titre, editeur, isbn, public_vise) { indicateur = indic; };
    Poesie(const Poesie &poesie);
    virtual void Affiche();
};

