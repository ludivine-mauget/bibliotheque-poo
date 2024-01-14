//
// Created by Massi on 09/01/2024.
//

#ifndef BIBLIOTHEQUE_POO_THEATRE_H
#define BIBLIOTHEQUE_POO_THEATRE_H

#include "Livre.h"
#include <iostream>

using namespace std;

class Theatre : public Livre {
private :
    string genre;

public :
    Theatre(int code, const string &auteur, const string &titre, const string &editeur, const string &isbn,
            const string &public_vise, const string &genre);
    Theatre(const Theatre* r);
    void affiche();
    const string &getGenre() const;

    void setGenre(const string &genre);
};


#endif //BIBLIOTHEQUE_POO_THEATRE_H
