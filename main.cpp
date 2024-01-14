//
// Created by Ludivine Mauget on 09/01/2024.
//

#include "BD.h"
#include "Bibliotheque.h"
#include "Adherent.h"
#include "Livre.h"
#include "Poesie.h"
#include "Roman.h"
#include "Theatre.h"
#include "Album.h"

#include <iostream>

using namespace std;

int main(){
    cout << "Hello World !" << endl;
    // Creer un livre avec le constructeur de la classe Livre
    Livre l1(1, "Victor Hugo", "Les Misérables", "Gallimard", "978-2-07-041699-3", "Adultes");

    Roman r1(2, "Albert Camus", "L'Etranger", "Gallimard", "978-2-07-036002-4", "Adulte", "Fiction Philosophique");

    l1.affiche();
    r1.affiche();


    Bibliotheque b1("Bibliothèque de la ville", 100);

    Adherent a1("Mauget", "Ludivine", "1 rue de la Paix Dieu", &b1);
    Adherent a2("Massif", "Damien", "1 rue de la Paix Dieu", &b1);
    Adherent a3("Bernard", "Kévin", "2 rue de la Paix Dieu", &b1);
    a1.afficheAdherent();

    Album album1(3, "Maurice Sendak", "Max et les Maximonstres", "Ecole des loisirs", "978-2-211-01025-9", "Enfants", PHOTO);
    return 0;
}