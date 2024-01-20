//
// Created by Ludivine Mauget on 09/01/2024.
//


#include "Bibliotheque.h"
#include "Adherent.h"
#include "Livre.h"
#include "NoeudLivre.h"
#include "Roman.h"
#include "Theatre.h"
#include "BD.h"
#include "Album.h"



#include <iostream>

using namespace std;

int main(){
    cout << "Hello World !" << endl;
    Livre l1(1, "Victor Hugo","Les Miserables" , "Gallimard", "978-2-07-041699-3", "Roman");

    l1.affiche();

    Bibliotheque b1("Bibliothèque de l'Université de Lille", 5);
    Adherent a1("Mauget", "Ludivine", "Rue de la Paix", &b1);

    // Ajoute livre bib
    b1.acheterLivre(l1);

    cout << "-------------------------" << endl;
    // Emprunt
    a1.emprunterLivre(1);


    // Affichage
    b1.afficheBibliotheque();
    a1.afficheAdherent();

    return 0;
}