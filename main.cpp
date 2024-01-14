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

#include <iostream>

using namespace std;

int main(){
    cout << "Hello World !" << endl;

    Bibliotheque bibliotheque("Alcazar", 5);

    Livre *livre1 = new Livre(1, "Auteur1", "Titre1", "Editeur1", "11111", "Tout public");
    Livre *livre2 = new Livre(2, "Auteur2", "Titre2", "Editeur2", "22222", "Tout public");

    Adherent *adherent1 = new Adherent("Mauget", "Ludivine", "1 Rue de la Paix", &bibliotheque);
    Adherent *adherent2 = new Adherent("Massif", "Ludivine", "2 Rue de la Paix", &bibliotheque);

    bibliotheque.ajouterAdherent(*adherent1);
    bibliotheque.ajouterAdherent(*adherent2);

    bibliotheque.acheterLivre(*livre1);
    bibliotheque.acheterLivre(*livre2);

    int n = bibliotheque.getIndiceLivre(1);
    int l = bibliotheque.getIndiceLivre(2);
    int m = bibliotheque.getIndiceLivre(4);

    return 0;
}