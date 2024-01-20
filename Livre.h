//
// Created by Massif on 08/01/2024.
//

#ifndef BIBLIOTHEQUE_POO_LIVRE_H
#define BIBLIOTHEQUE_POO_LIVRE_H

#include <iostream>

using namespace std;


class Livre {
public:
    Livre(int code, const string& auteur, const string& titre, const string& editeur, const string& isbn,
        const string& public_vise);
    Livre();
    ~Livre();
    Livre(const Livre& livre);
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
    const bool& getEtat() const;
    void setEtat(const bool& etat);
    virtual void affiche();
    enum TYPE { LIVRE, BD, POESIE, ROMAN, THEATRE, ALBUM };


protected:
    int type;
    int code{};
    string auteur;
    string titre;
    string editeur;
    string ISBN;
    string publicVise;
    bool etat;
};


#endif //BIBLIOTHEQUE_POO_LIVRE_H
