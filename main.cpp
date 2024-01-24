//
// Created by Ludivine Mauget on 09/01/2024.
//


#include "Bibliotheque.h"
#include "Adherent.h"
#include "Livre.h"
#include "Roman.h"
#include "Theatre.h"
#include "BD.h"
#include "Album.h"



#include <iostream>

using namespace std;

int main() {

    Livre livre1("Victor Hugo", "Les Misérables", "Gallimard", "978-2-07-041699-3", "Tout public");
    Livre livre2("François Villon", "Poésies", "Gallimard", "978-3-07-041699-3", "Tout public");
    Livre livre3("Dante", "La Divine Comédie", "Gallimard", "978-4-07-041699-3", "Tout public");
    BD bd1("Hergé", "Tintin", "Casterman", "978-2-203-00112-0", "Tout public", "Hergé");
    BD bd2("Albert Uderzo", "Astérix", "Gallimard", "978-2-07-042277-2", "Tout public", "Goscinny");
    Theatre theatre1("Molière", "Le Bourgeois Gentilhomme", "Gallimard", "978-2-07-11111-3", "Tout public",
                     "XVIIe siècle");
    Roman roman1("Jules Verne", "Voyage au centre de la Terre", "Gallimard", "978-2-07-22222-3", "Tout public",
                 "Aventure");
    Album album1("Bastien Vivès", "Le goût du chlore", "Casterman", "978-2-203-33333-1", "Tout public", "dessin");

    cout <<"---Affichage de livre1---" << endl;
    livre1.affiche();
    cout <<"---Affichage de bd1---" << endl;
    bd1.affiche();

    Bibliotheque b1("Bibliothèque de l'Université de Lille", 2);
    Bibliotheque b2("Bibliothèque de Aix-Marseille", 4);
    Adherent a1("Mauget", "Ludivine", "Rue de la Paix", &b1);
    Adherent a2("Massif", "Damien", "Rue de la République", &b2);
    Adherent a1bis("Bernard", "Kévin", "Rue de la libération", &b1);

    // "La bibliothèque 1 achète livre 1 et bd1"
    b1.acheterLivre(livre1); // 0
    b1.acheterLivre(bd1); // 1
    b1.acheterLivre(bd2); // 2
    b2.acheterLivre(roman1); // 0
    b2.acheterLivre(album1); // 1

    cout << "---Affichage des livres de b1---" << endl;
    b1.afficheLivres(); // categorie 0: livres
    cout << "---Affichage des BD de b1---" << endl;
    b1.afficheLivres(1); // categorie 1: BD




    //Emprunt
    a1.emprunterLivre(1); // bd1 ok
    cout << "---Emprunt d'un livre qui n'existe pas---" << endl;
    a1.emprunterLivre(5); // pas de code 5
    a2.emprunterLivre(0);
    a2.emprunterLivre(1);

    // Affichage
    b1.afficheBibliotheque();
    cout << "-------------------------" << endl;
    b2.afficheBibliotheque();
    cout << "-------------------------" << endl;
    a1.afficheAdherent();
    cout << "-------------------------" << endl;
    a2.afficheAdherent();
    cout << "-------------------------" << endl;


    // Rendre
    a1.rendreLivre(1);


    cout<< "Test si un adhérent peut emprunter plus de livre qu'il ne peut" << endl;
    a1.afficheAdherent();
    a1.emprunterLivre(0);
    a1.emprunterLivre(1);
    a1.emprunterLivre(2);
    a1.afficheAdherent();

    cout << " ---Test rendre livre---" << endl;
    a1.rendreLivre(0);
    a1.rendreLivre(1);
    a1.afficheAdherent();
    cout << "---On voit que les livres ont bien été rendus---" << endl;

    cout<< "---Test si un adhérent peut emprunter un livre déjà emprunté---" << endl;
    a1.emprunterLivre(0);
    a1.emprunterLivre(0);
    cout << "---Affiche état livre 0---" << endl;
    cout << b1.getLivre(b1.getIndiceLivre(0)).getEtat() << endl;
    a1bis.emprunterLivre(0);

    a1.afficheAdherent();
    cout << "-------------------------" << endl;
    a1bis.afficheAdherent();
    // Test LUDIVINE

    cout << "---Affichage bibliothèque avant emprunt :---" << endl;
    b1.afficheBibliotheque();
    b2.afficheBibliotheque();
    cout << "-------------------------" << endl;
    cout << "---Affichage état avant emprunt :---" << endl;
    cout << b1.getLivre(b1.getIndiceLivre("978-2-07-041699-3")).getEtat() << endl;
    cout << "-------------------------" << endl;

    b2.emprunterLivre("978-2-07-041699-3", b1);
    cout << "---Emprunt double d'un livre à une bibliotheque---" << endl;
    b2.emprunterLivre("978-2-07-041699-3", b1);
    cout << "---Affichage état après emprunt :---" << endl;
    cout << b1.getLivre(b1.getIndiceLivre("978-2-07-041699-3")).getEtat() << endl;
    cout << "-------------------------" << endl;
    cout << "---Affichage bibliothèque 1 après emprunt :---" << endl;
    b1.afficheBibliotheque();
    cout << "---Affichage bibliothèque 2 après emprunt :---" << endl;
    b2.afficheBibliotheque();
    cout << "-------------------------" << endl;


    cout << "---Suppression d'un livre avec son code---" << endl;
    cout << "-- Avant suppression--" << endl;
    b1.afficheLivres();
    b1.supprimerLivre(b1.getLivre(b1.getIndiceLivre(0)));
    cout << "-- Après suppression--" << endl;
    b1.afficheLivres();
    cout << "-- Rajoute avec opérateur + --" << endl;
    b1 + livre1;
    b1.afficheLivres();

// Rendre livres prêtés non empruntés
    cout << "---Rendre livres prêtés non empruntés---" << endl;
    cout << "---Affichage bibliothèque 1 avant rendu---" << endl;
    b2.afficheBibliotheque();







    return 0;
}

