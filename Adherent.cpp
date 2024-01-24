#include "Adherent.h"
#include "Bibliotheque.h"

Adherent::Adherent(string nom, string prenom, string adresse, Bibliotheque &bibliotheque) : bibliotheque(bibliotheque) {
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    idAdherent = 0; // on donne un id a l'adherent et on incremente le nombre d'adherent
    // Assignation de l'adhérent à la bibliothèque
    bibliotheque.ajouterAdherent(this);
    nbMaxEmprunt = bibliotheque.getNbLivresMax();
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

void Adherent::setIdAdherent(const int& id) {
    idAdherent = id;
}


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
        cout << nom << " " << prenom << " a atteint le nombre maximum d'emprunt autorisé par : " << bibliotheque.getNom() << endl;
        return;
    }
    int id = bibliotheque.getIndiceLivre(codeLivre);
    if (id == -1) {
        cout << "Le livre demandé n'existe pas dans la bibliothèque : " << bibliotheque.getNom() << endl;
        return;
    }
    Livre* livre = bibliotheque.getLivre(id);
    try {
        if (!livre->getEtat()) {
            livre->setEtat(true);
            ajouteLivre(*livre);
        }
        else {
            throw bibliotheque.getNom();
        }
    }
    catch(int n) 
    {
        cout << nom << " " << prenom << " ne peut plus emprunter de livre." << endl;        
    }
    catch (string name) {
        cout << "La bibliothèque " << name << "a déjà prêté ce livre" << endl;
    }
    bibliotheque.getLivre(id)->setEtat(true);
}

void Adherent::rendreLivre(int code)
{
    // vérifier que la liste n'est pas vide
    if (listeLivre == nullptr) {
        cout << this->getNom() << " n'a pas de livre à rendre." << endl;
        return;
    }
    // cherche livre dans listeLivre
    NoeudLivre *tmp = listeLivre;
    NoeudLivre *tmpPrec = nullptr;
    while (tmp != nullptr && tmp->getLivre().getCode() != code) {
        tmpPrec = tmp;
        tmp = tmp->getSuivant();
    }
    if (tmp == listeLivre) {
        // on est au début de la liste
        listeLivre = listeLivre->getSuivant();
        delete tmp;
    }
    else {
        if (tmp == nullptr) {
            cout << "Le livre n'est pas emprunté par " << this->getNom() << " " << this->getPrenom() << endl;
            return;
        }
        // on est au milieu ou à la fin de la liste
        tmpPrec->setSuivant(tmp->getSuivant());
        delete tmp;
    }
    bibliotheque.getLivre(bibliotheque.getIndiceLivre(code))->setEtat(false); // on change l'état du livre dans la bibliothèque
}

void Adherent::afficheAdherent() {
    cout << "Nom : " << nom << endl;
    cout << "Prénom : " << prenom << endl;
    cout << "Adresse : " << adresse << endl;
    cout << "Id : " << idAdherent << endl;
    cout << "Bibliothèque : " << bibliotheque.getNom() << endl;
    cout << "Livres empruntés : " << endl;
    NoeudLivre* tmp = listeLivre;
    while (tmp != nullptr) {
        cout << tmp->getLivre().getTitre() << endl;
        tmp = tmp->getSuivant();
    }
}
