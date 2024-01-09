//
// Created by Ludivine Mauget on 09/01/2024.
//

#ifndef BIBLIOTHEQUE_POO_BD_H
#define BIBLIOTHEQUE_POO_BD_H

#include "Livre.h"

class BD : public Livre {
private:
    string dessinateur;
public:
    BD(int code, const string &auteur, const string &titre, const string &editeur, const string &isbn,
       const string &public_vise, const string &dessinateur);
    BD();
    BD(const string &dessinateur);
    const string &getDessinateur() const;
    void setDessinateur(const string &dessinateur);
    void affiche();
};


#endif //BIBLIOTHEQUE_POO_BD_H
