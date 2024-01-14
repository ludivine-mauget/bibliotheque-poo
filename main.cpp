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

    Livre *livre1 = new Livre(1, "Mauget", "Ludivine", "1 Rue de la Paix", "123456789", "Tout public");

    Adherent *adherent1 = new Adherent("Mauget", "Ludivine", "1 Rue de la Paix", &bibliotheque);
    Adherent *adherent2 = new Adherent("Massif", "Ludivine", "2 Rue de la Paix", &bibliotheque);

    bibliotheque.ajouterAdherent(*adherent1);
    bibliotheque.ajouterAdherent(*adherent2);

    bibliotheque.acheterLivre(*livre1);

    bibliotheque.afficheBibliotheque();
    livre1->affiche();
    adherent1->afficheAdherent();
    adherent2->afficheAdherent();
    bibliotheque.afficheAdherents();
    bibliotheque.afficheLivres();

    return 0;
}