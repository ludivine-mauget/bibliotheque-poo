//
// Created by Ludivine Mauget on 09/01/2024.
//

#include "Livre.h"

#include <iostream>

using namespace std;

int main(){
    cout << "Hello World !" << endl;
    Livre l1(1, "Les Misérables", "Victor Hugo", "Gallimard", "978-2-07-041699-3", "Roman");

    l1.affiche();

//    Bibliotheque bibliotheque("Alcazar", 5);
//
//    Adherent adherent1("Mauget", "Ludivine", "Rue de la Paix", &bibliotheque, 2);
//
//    bibliotheque.ajouterAdherent(adherent1);
//
//    bibliotheque.acheterLivre(*livre1);
//    bibliotheque.acheterLivre(*livre2);
//
//    int n = bibliotheque.getIndiceLivre(1);
//    int l = bibliotheque.getIndiceLivre(2);
//    int m = bibliotheque.getIndiceLivre(4);

    return 0;
}