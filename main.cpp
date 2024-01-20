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

int main(){
    Livre livre1("Victor Hugo","Les Misérables" , "Gallimard", "978-2-07-041699-3", "Tout public");
    Livre livre2("François Villon","Poésies" , "Gallimard", "978-3-07-041699-3", "Tout public");
    Livre livre3("Dante","La Divine Comédie" , "Gallimard", "978-4-07-041699-3", "Tout public");
    BD bd1("Hergé", "Tintin", "Casterman", "978-2-203-00112-0", "Tout public", "Hergé");
    Theatre theatre1("Molière", "Le Bourgeois Gentilhomme", "Gallimard", "978-2-07-041699-3", "Tout public", "XVIIe siècle");
    Roman roman1("Jules Verne", "Voyage au centre de la Terre", "Gallimard", "978-2-07-041699-3", "Tout public", "Aventure");
    Album album1("Bastien Vivès", "Le goût du chlore", "Casterman", "978-2-203-00112-1", "Tout public", "dessin");
    // Affichage des livres, on vérifie que tous les codes sont à 0
    //livre1.affiche();
    //cout << "-------------------------" << endl;
    //bd1.affiche();
    //cout << "-------------------------" << endl;
    //theatre1.affiche();
    //cout << "-------------------------" << endl;
    //roman1.affiche();
    //cout << "-------------------------" << endl;
    //album1.affiche();
    // cout << "-------------------------" << endl;

    Bibliotheque b1("Bibliothèque de l'Université de Lille", 2);
    Bibliotheque b2("Bibliothèque de Aix-Marseille", 4);
    Adherent a1("Mauget", "Ludivine", "Rue de la Paix", &b1);
    Adherent a2("Massif", "Damien", "Rue de la République", &b2);
    Adherent a3("Bernard", "Kévin", "Rue de la libération", &b1);

    // Ajoute livre bib, on vérifie que les codes sont incrémentés
    b1.acheterLivre(livre1); // 0
    b1.acheterLivre(bd1); // 1
    b1.acheterLivre(theatre1); // 2
    b2.acheterLivre(roman1); // 0
    b2.acheterLivre(album1); // 1

    //Emprunt
    a1.emprunterLivre(1); // bd1 ok
    a1.emprunterLivre(2); // theatre1 ok
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

    // TINTIN
    bool etat1 = b1.getLivre(b1.getIndiceLivre("978-2-203-00112-0")).getEtat();
    cout << "Etat du livre : " << etat1 << endl;
    cout << "-------------------------" << endl;

    // Affichage
    a1.afficheAdherent();
    cout << "-------------------------" << endl;

    b2.emprunterLivre("978-2-203-00112-0", b1);
    b2.afficheBibliotheque();
    cout << "-------------------------" << endl;

    bool etat2 = b1.getLivre(b1.getIndiceLivre("978-2-203-00112-0")).getEtat();
    cout << "Etat du livre : " << etat2 << endl;
    cout << "-------------------------" << endl;

    b2.rendreLivre("978-2-203-00112-0", b1);
    b2.afficheBibliotheque();
    cout << "-------------------------" << endl;

    bool etat3 = b1.getLivre(b1.getIndiceLivre("978-2-203-00112-0")).getEtat();
    cout << "Etat du livre : " << etat3 << endl;
    cout << "-------------------------" << endl;

    cout<< "Test si un adhérent peut emprunter plus de livre qu'il ne peut" << endl;
    a1.rendreLivre(0);
    a1.afficheAdherent();
    a1.emprunterLivre(0);
    a1.emprunterLivre(1);
    a1.emprunterLivre(2);
    a1.afficheAdherent();
    a1.rendreLivre(0);
    a1.rendreLivre(1);
    cout << "-------------------------" << endl;

    cout<< "Test si un adhérent peut emprunter un livre déjà emprunté" << endl;
    a1.afficheAdherent();
    cout << "-----------" << endl;
    a3.afficheAdherent();
    cout << "-----------" << endl;
    a1.emprunterLivre(0);
    a1.emprunterLivre(0);
    a3.emprunterLivre(0);
    a1.afficheAdherent();
    cout << "-----------" << endl;
    a3.afficheAdherent();
    cout << "-------------------------" << endl;


    return 0;
}