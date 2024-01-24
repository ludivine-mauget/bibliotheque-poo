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
template <>
int Bibliotheque::getIndiceLivre<const char*>(const char* arg) {
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

void Bibliotheque::afficheLivres(const int& categorie) {
    for (auto livre : livres) {
        if (livre->getType() == categorie) {
            cout << livre->getTitre() << endl;
        }
    }
}

void Bibliotheque::emprunterLivre(const string& isbn, Bibliotheque bibliotheque) {
    int indice = bibliotheque.getIndiceLivre(isbn);
    if (bibliotheque.getLivre(indice).getEtat()) {
        cout << "Le livre est déjà emprunté" << endl;
        return;
    }
    auto* livre = new Livre(bibliotheque.getLivre(indice));
    livresEmpruntes.push_back(livre);
    bibliothequeCorrespondantes.push_back(&bibliotheque);
    livres.push_back(livre);
    bibliotheque.livres[indice]->setEtat(true);
}

void Bibliotheque::afficheLivresEmpruntes() {
    for (auto livre : livresEmpruntes) {
        cout << livre->getTitre() << endl;
    }
}

void Bibliotheque::rendreLivre(const string& isbn, Bibliotheque bibliotheque) {
    int indice = getIndiceEmprunt(isbn);
    int indice1 = getIndiceLivre(isbn);
    livresEmpruntes.erase(livresEmpruntes.begin() + indice);
    livres.erase(livres.begin() + indice1);
    int indice2 = bibliotheque.getIndiceLivre(isbn);
    bibliotheque.livres[indice2]->setEtat(false);
}

void Bibliotheque::rendreLivreSansConnaitreBiblio(const std::string &isbn) {
    // Trouver à quelle bibliothèque appartient le livre
    int indice = getIndiceEmprunt(isbn);
    Bibliotheque* bibliotheque = bibliothequeCorrespondantes[indice];
    rendreLivre(isbn, *bibliotheque);
}

void Bibliotheque::rendreLivresPretesNonEmpruntes() {
    for (int i = 0; i < livresEmpruntes.size(); i++) {
        if (!livresEmpruntes[i]->getEtat()) {
            rendreLivre(livresEmpruntes[i]->getIsbn(), *bibliothequeCorrespondantes[i]);
        }
    }
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
    return -5;
}

void Bibliotheque::ajouterAdherent(Adherent* adherent) {
    adherents.push_back(adherent);
    adherent->setIdAdherent(numAdherent);
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

void Bibliotheque::operator+(const Livre& livre) {
    acheterLivre(livre);
}

