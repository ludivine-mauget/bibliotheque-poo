//
// Created by Massif on 08/01/2024.
//

#ifndef BIBLIOTHEQUE_POO_LIVRE_H
#define BIBLIOTHEQUE_POO_LIVRE_H

#include <iostream>
#include "Bibliotheque.h"
#include "Adherent.h"
#include "Emprunteur.h"

using namespace std;


class Livre {
public:
    Livre(int code, const string& auteur, const string& titre, const string& editeur, const string& isbn,
        const string& public_vise);
    Livre();
    int getCode() const;
    void setCode(int code);
    const string& getAuteur() const;
    void setAuteur(const string& auteur);
    const string& getTitre() const;
    void setTitre(const string& titre);
    const string& getEditeur() const;
    void setEditeur(const string& editeur);
    const string& getIsbn() const;
    void setIsbn(const string& isbn);
    const string& getPublicVise() const;
    void setPublicVise(const string& publicVise);
    virtual void affiche();
    const Emprunteur getEmprunteur();
    enum types { LIVRE, BD, POESIE, ROMAN, PIECE, ALBUM };

protected:
    int type;
    int code{};
    string auteur;
    string titre;
    string editeur;
    string ISBN;
    string publicVise;
    Emprunteur *emprunte_par; // TODO
};


#endif //BIBLIOTHEQUE_POO_LIVRE_H
