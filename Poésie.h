#pragma once
#include "Livre.h"
using namespace std;

enum Indic { vers, prose, both };

class Po�sie :
    public Livre
{
private:
    Indic indicateur;
public:
    Po�sie():Livre() {};
    Po�sie(int code, const string& auteur, const string& titre, const string& editeur, const string& isbn, const string& public_vise, const Indic& indic) :Livre(code, auteur, titre, editeur, isbn, public_vise) { indicateur = indic; };
    Po�sie(const Po�sie &po�sie); 
    virtual void Affiche();
};

