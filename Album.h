#ifndef BIBLIOTHEQUE_POO_ALBUM_H
#define BIBLIOTHEQUE_POO_ALBUM_H

#include "Livre.h"
using namespace std;



class Album : public Livre
{
public:
    Album();
    Album(const string& auteur, const string& titre, const string& editeur, const string& isbn,
        const string& public_vise,const string& illu);
    const string& getIllustration();
    void SetIllustration(const string& illustration);
    void affiche();

private:
    string illustration;
};

#endif //BIBLIOTHEQUE_POO_ALBUM_H