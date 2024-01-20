#ifndef BIBLIOTHEQUE_POO_POESIE_H
#define BIBLIOTHEQUE_POO_POESIE_H

#include "Livre.h"
using namespace std;


class Poesie : public Livre
{
private:
    string indicateur;
public:
    Poesie();
    Poesie(const string& auteur, const string& titre, const string& editeur, const string& isbn, const string& public_vise, const string& indic);
    const string& getIndicateur() const;
    void setIndicateur(const string& indic);
    void Affiche();
};

#endif //BIBLIOTHEQUE_POO_POESIE_H

