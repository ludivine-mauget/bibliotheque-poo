#include "Adherent.h"
#include "Bibliotheque.h"

Adherent::Adherent()
{
	nom = "";
	prenom = "";
	adresse = "";
	nbAdherent = IdAdherent;
	bibliotheque = Bibliotheque();
	maxEmprunt = 0;
	livreEmpruntes = new Livre[maxEmprunt];	
	IdAdherent++;
}

Adherent::Adherent(string n, string p)
{
	nom = n;
	prenom = p;
	nbAdherent = IdAdherent;
	bibliotheque = Bibliotheque();
	maxEmprunt = 0;
	livreEmpruntes = new Livre[maxEmprunt];	
	IdAdherent++;
}

Adherent::~Adherent()
{
	if (livreEmpruntes != NULL) {
		delete livreEmpruntes;
	}
}

void Adherent::Emprunter()
{
}

void Adherent::Rendre()
{
	
}

const string& Adherent::getNom() const
{
	return nom;
}

void Adherent::setNom(const string& nom)
{
	this->nom = nom;
}

const string& Adherent::getPrenom() const
{
	return prenom;
}

void Adherent::setPrenom(const string& prenom)
{
	this->prenom = prenom;
}

const string& Adherent::getAdresse() const
{
	return adresse;
}

void Adherent::setAdresse(const string& adresse)
{
	this->adresse = adresse;
}

const int& Adherent::getNbAdherent() const
{
	return nbAdherent;
}

const Bibliotheque& Adherent::getBibliotheque() const
{
	return bibliotheque;
}

void Adherent::setBibliotheque(const Bibliotheque& biblio)
{
	bibliotheque = biblio;
}

const Livre* Adherent::getLivres() const
{
	return livreEmpruntes;
}

const int& Adherent::getMaxEmprunt() const
{
	return maxEmprunt;
}

void Adherent::setMaxEmprunt(const int& seuil)
{
	Livre* newTabLivres = new Livre[seuil];
	for (int i = 0; i < maxEmprunt; i++)
	{
		newTabLivres[i] = livreEmpruntes[i];
	}
	maxEmprunt = seuil;
	livreEmpruntes = newTabLivres;
}
