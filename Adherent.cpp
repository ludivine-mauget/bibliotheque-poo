using namespace std;

#include "Adherent.h"

int Adherent::nbAdherent = 0;

Adherent::Adherent(string nom, string prenom, string adresse, Bibliotheque* bibliotheque) {
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->idAdherent = nbAdherent++; // on donne un id a l'adherent et on incremente le nombre d'adherent
    this->bibliotheque = bibliotheque;
    nbMaxEmprunt = bibliotheque->getNbLivresMax();
    listeLivre = nullptr;
}

Adherent::~Adherent() = default;

const string& Adherent::getNom() const {
    return nom;
}

void Adherent::setNom(const string& nom) {
    Adherent::nom = nom;
}

const string& Adherent::getPrenom() const {
    return prenom;
}

void Adherent::setPrenom(const string& prenom) {
    Adherent::prenom = prenom;
}

const string& Adherent::getAdresse() const {
    return adresse;
}

void Adherent::setAdresse(const string& adresse) {
    Adherent::adresse = adresse;
}

const int& Adherent::getIdAdherent() const {
    return idAdherent;
}

//void Adherent::setMaxEmprunt(const int& max)
//{
//    try {
//        if (nbMaxEmprunt > max) {
//            throw nbMaxEmprunt-max;
//        }
//        else {
//            nbMaxEmprunt = max;
//        }
//    }
//    catch (int n) {
//        cout << nom << " " << prenom << " doit rendre " << n << " livre(s)." << endl;
//    }
//}

const int& Adherent::getMaxEmprunt() const
{
    return nbMaxEmprunt;
}

int Adherent::getNbEmprunts()
{
int i = 0;
    NoeudLivre* tmp = listeLivre;
    while (tmp != nullptr) {
        i++;
        tmp = tmp->getSuivant();
    }
    return i;
}

void Adherent::ajouteLivre(Livre livre) {
    NoeudLivre* n = new NoeudLivre(livre, listeLivre);
    listeLivre = n;
}

void Adherent::supprimeLivre(Livre livre) { //supr un element
    NoeudLivre *tmp = listeLivre;
    NoeudLivre *tmpPrec = nullptr;
    while (tmp != nullptr && tmp->getLivre().getCode() != livre.getCode()) {
        tmpPrec = tmp;
        tmp = tmp->getSuivant();
    }
    if (tmp == listeLivre) {
        // on est au début de la liste
        listeLivre = listeLivre->getSuivant();
        delete tmp;
    }
    else {
        // on est au milieu ou à la fin de la liste
        tmpPrec->setSuivant(tmp->getSuivant());
        delete tmp;
    }

}

void Adherent::emprunterLivre(int codeLivre) {
    if (getNbEmprunts() >= nbMaxEmprunt) {
        cout << nom << " " << prenom << " a atteint le nombre maximum d'emprunt autorisé par." << bibliotheque->getNom() << endl;
        return;
    }
    int id = bibliotheque->getIndiceLivre(codeLivre);
    try {
        if (!bibliotheque->getLivre(id).getEtat()) {
            ajouteLivre(bibliotheque->getLivre(id));
        }
        else {
            throw bibliotheque->getNom();
        }
    }
    catch(int n) 
    {
        cout << nom << " " << prenom << " ne peut plus emprunter de livre." << endl;        
    }
    catch (string name) {
        cout << "La bibliothèque " << name << "a déjà prêté ce livre" << endl;
    }
    bibliotheque->getLivre(id).setEtat(true);
}

void Adherent::rendreLivre(Livre livre) 
{
    // cherche livre dans listeLivre
    NoeudLivre *tmp = listeLivre;
    NoeudLivre *tmpPrec = nullptr;
    while (tmp != nullptr && tmp->getLivre().getCode() != livre.getCode()) {
        tmpPrec = tmp;
        tmp = tmp->getSuivant();
    }
    if (tmp == listeLivre) {
        // on est au début de la liste
        listeLivre = listeLivre->getSuivant();
        delete tmp;
    }
    else {
        // on est au milieu ou à la fin de la liste
        tmpPrec->setSuivant(tmp->getSuivant());
        delete tmp;
    }
    bibliotheque->getLivre(bibliotheque->getIndiceLivre(livre.getCode())).setEtat(false); // on change l'état du livre dans la bibliothèque
}

void Adherent::afficheAdherent() {
    cout << "Nom : " << nom << endl;
    cout << "Prénom : " << prenom << endl;
    cout << "Adresse : " << adresse << endl;
    cout << "Id : " << idAdherent << endl;
    cout << "Bibliothèque : " << bibliotheque->getNom() << endl;
    cout << "Livres empruntés : " << endl;
    NoeudLivre* tmp = listeLivre;
    while (tmp != nullptr) {
        tmp->getLivre().affiche();
        tmp = tmp->getSuivant();
    }
}
