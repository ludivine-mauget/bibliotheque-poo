#pragma once
#include "Livre.h"
using namespace std;



class Album : public Livre
{
public:
    Album();
    Album(const int& code, const string& auteur, const string& titre, const string& editeur, const string& isbn,
        const string& public_vise,const string& illu);
    const string& getIllustration();
    void SetIllustration(const string& illustration);
    void affiche();

private:
    string illustration;
};
