#pragma once
#include "Livre.h"
using namespace std;

enum Indic { vers, prose, both };

class Poésie :
    public Livre
{
private:
    Indic indicateur;
public:
    Poésie():Livre() {};
    Poésie(int code, const string& auteur, const string& titre, const string& editeur, const string& isbn, const string& public_vise, const Indic& indic) :Livre(code, auteur, titre, editeur, isbn, public_vise) { indicateur = indic; };
    Poésie(const Poésie &poésie); 
    virtual void Affiche();
};

