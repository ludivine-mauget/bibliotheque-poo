#pragma once
#include "Livre.h"
using namespace std;

enum Illu { PHOTO, DESSIN, BOTH };

class Album : public Livre
{
public:
    
    Album();
    Album(int code, const string& auteur, const string& titre, const string& editeur, const string& isbn,
        const string& public_vise,Illu& illu);
    const Illu& getIllustration();
    void SetIllustration(const Illu& illustration);
    void affiche();
private:
    Illu illustration;
};