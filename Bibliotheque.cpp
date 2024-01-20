//
// Created by Massif on 08/01/2024.
//

#include "Bibliotheque.h"


using namespace std;

template <typename T>
int Bibliotheque::getIndiceLivre(T arg) {
}

template <>
int Bibliotheque::getIndiceLivre<string>(string arg) {
    int i = 0;
    try{
        for (auto l: livres) {
            if (l->getIsbn() == arg) {
                return i;
            }
            i++;
        }
        throw runtime_error("Le livre n'existe pas");
    } catch (runtime_error &e) {
        cerr << "Exception trouvée : " << e.what() << endl;
    }
    return -1;
}

template <>
int Bibliotheque::getIndiceLivre<int>(int arg) {
    int i = 0;
    try{
        for (auto l: livres) {
            if (l->getCode() == arg) {
                return i;
            }
            i++;
        }
        throw runtime_error("Le livre n'existe pas");
    } catch (runtime_error &e) {
        cerr << "Exception trouvée : " << e.what() << endl;
    }
    return -1;
}


Bibliotheque::Bibliotheque(string nom, int nbLivresMax){
    this->nom = nom;
    this->nbLivresMax = nbLivresMax;
    numAdherent = 0;
    idLivre = 0;
}

void Bibliotheque::afficheBibliotheque() {
    cout << "Nom de la bibliothèque : " << nom << endl;
    cout << "Nombre de livres maximum : " << nbLivresMax << endl;
    cout << "Liste des adhérents : " << endl;
    afficheAdherents();
    cout << "Liste des livres : " << endl;
    afficheLivres();
    cout << "Liste des livres empruntés : " << endl;
    afficheLivresEmpruntes();
}

void Bibliotheque::afficheAdherents() {
    for (auto adherent : adherents) {
        cout << adherent->getNom() << endl;
    }
}

void Bibliotheque::afficheLivres() {
    for (auto livre : livres) {
        cout << livre->getTitre() << endl;
    }
}

void Bibliotheque::afficheLivres(const string& categorie) {
    for (auto livre : livres) {
        if (livre->getPublicVise() == categorie) {
            cout << livre->getTitre() << endl;
        }
    }
}

void Bibliotheque::emprunterLivre(const string& isbn, Bibliotheque bibliotheque) {
    int indice = bibliotheque.getIndiceLivre(isbn); // On cherche l'indice du livre dans la bibliothèque à laquelle on emprunte
    Livre livre = bibliotheque.getLivre(indice); // On crée une copie du livre dans notre bibliothèque
    livresEmpruntes.push_back(&livre); // On ajoute le livre à la liste des livres empruntés
    livres.push_back(&livre); // On ajoute le livre à la liste des livres de notre bibliothèque
    bibliotheque.getLivre(indice).setEtat(true); // On change l'état du livre dans la bibliothèque à laquelle on emprunte
}

void Bibliotheque::afficheLivresEmpruntes() {
    for (auto livre : livresEmpruntes) {
        cout << livre->getTitre() << endl;
    }
}

void Bibliotheque::rendreLivre(string isbn, Bibliotheque bibliotheque) {
    int indice = getIndiceEmprunt(isbn); // On cherche l'indice du livre dans la liste des livres empruntés
    int indice1 = getIndiceLivre(isbn); // On cherche l'indice du livre dans la liste des livres de notre bibliothèque
    getLivre(indice).~Livre(); // On supprime le livre
    livresEmpruntes.erase(livresEmpruntes.begin() + indice); // On supprime le livre de la liste des livres empruntés
    livres.erase(livres.begin() + indice1); // On supprime le livre de la liste des livres de notre bibliothèque
    int indice2 = bibliotheque.getIndiceLivre(isbn); // On cherche l'indice du livre dans la liste des livres de notre bibliothèque
    bibliotheque.getLivre(indice2).setEtat(false); // On change l'état du livre dans la bibliothèque à laquelle on emprunte
}

void Bibliotheque::acheterLivre(const Livre& livre) {
    auto* livre1 = new Livre(livre); // On crée une copie du livre
    livres.push_back(livre1); // On ajoute la copie du livre à la liste des livres de notre bibliothèque
    livre1->setCode(idLivre); // On change le code du livre
    idLivre++; // On incrémente le code du livre
}

void Bibliotheque::supprimerLivre(const Livre& livre) {
    int indice = getIndiceLivre(livre.getCode());
    livres.erase(livres.begin() + indice);
}



int Bibliotheque::getIndiceEmprunt(const string& isbn) {
    int i = 0;
    try {
        for (auto l : livresEmpruntes) {
            if (l->getIsbn() == isbn) {
                return i;
            }
            i++;
            if (i == livresEmpruntes.size()) {
                throw runtime_error("Le livre n'existe pas");
            }
        }
    } catch (runtime_error &e) {
        cerr << "Exception trouvée : " << e.what() << endl;
    }
    return -1;
}

void Bibliotheque::ajouterAdherent(Adherent adherent) {
    adherents.push_back((Adherent*)&adherent);
    adherent.setIdAdherent(numAdherent);
    numAdherent++;
}

void Bibliotheque::supprimerAdherent(const Adherent& adherent) {
    int i = 0;
    for (auto a : adherents) {
        if (a->getIdAdherent() == adherent.getIdAdherent()) {
            adherents.erase(adherents.begin() + i);
            a->~Adherent();
        }
        i++;
    }
}

string Bibliotheque::getNom(){
    return nom;
}

void Bibliotheque::setNom(const string &n) {
    this->nom = n;
}

int Bibliotheque::getNbLivresMax() {
    return nbLivresMax;
}

void Bibliotheque::setNbLivresMax(int nbLivresMax) {
    this->nbLivresMax = nbLivresMax;
}

Livre Bibliotheque::getLivre(int indice) {
    return *livres[indice];
}

