#pragma once
#include "Livre.h"
using namespace std;
class Roman :
    public Livre
{
private:
    string genre;

public :
    Roman(const string &auteur, const string &titre, const string &editeur, const string &isbn,
          const string &public_vise, const string &genre);
    Roman(const Roman* r);
    void affiche();
    const string &getGenre() const;

    void setGenre(const string &genre);


};
