#include "ListeLivre.h"

ListeLivre::ListeLivre()
{
    tete = NULL;
    nbLivre = 0;
}

ListeLivre::ListeLivre(const ListeLivre& liste)
{
    tete = NULL;
    nbLivre = 0;
    NoeudLivre* livre = liste.tete;
    while (livre != NULL) {
        AddLivre(livre->livre);
        livre = livre->suivant;
    }
}

ListeLivre::~ListeLivre()
{
    NoeudLivre* current = tete;
    NoeudLivre* next = tete->suivant;
    while (next != NULL) {
        delete current;
        current = next;
        next = next->suivant;
    }
    delete tete;
}

Livre ListeLivre::getLivre(int position) const
{
    try {
        if (nbLivre > position || position < 0) {
            throw false;
        }
        else {
            if (position == 0) {
                return tete->livre;
            }
            int currentPos = 0;
            NoeudLivre* current = tete;
            while (currentPos < position) {
                current = current->suivant;
                currentPos++;
            }
            return current->livre;
        }
    }
    catch (bool b) {
        cout << "La liste ne contient que " << nbLivre << " Livre(s)";
    }
}

void ListeLivre::AddLivre(Livre newLivre, Adherent adherent)
{
    if (nbLivre < adherent.getMaxEmprunt()) {
        throw nbLivre;
    }
    NoeudLivre * newNoeud = new NoeudLivre(newLivre);
    if (tete == NULL) {
        tete = newNoeud;
        return;
    }
    NoeudLivre* next = tete;
    while (next->suivant != NULL) {
        next = next->suivant;
    }
    next->suivant = newNoeud;
    nbLivre++;
}

void ListeLivre::RemoveLivre(Livre livre)
{
    if (nbLivre <= 0) {
        return;
    }
    
    NoeudLivre* current = tete;
    NoeudLivre* next = tete->suivant;
    if (tete->livre.getIsbn() == livre.getIsbn()) {
        tete = next;
        delete current;
    }
    while (next!=NULL){
        if (next->livre.getIsbn() == livre.getIsbn()) {
            current->suivant = next->suivant;
            delete next;
            nbLivre--;
            break;
        }
    }
    throw livre.getIsbn();
}

void ListeLivre::affiche()
{
    NoeudLivre* currentLivre = tete;
    while (currentLivre != NULL) {
        currentLivre->livre.affiche();
        currentLivre = currentLivre->suivant;
    }
}
