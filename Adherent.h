#include <iostream>
using namespace std;
#include "Bibliotheque.h"
#include "Livre.h"

class Adherent
{
private:
	string nom;
	string prenom;
	string adresse;
	static int IdAdherent;
	int nbAdherent;
	Bibliotheque bibliotheque;
	Livre* livreEmpruntes;
	int maxEmprunt;
public:
	Adherent(); //assigne un num d'adherent
	Adherent(string n, string p); //avec nom, premnom
	~Adherent();
	void Emprunter();
	void Rendre();

	const string& getNom() const;
	void setNom(const string& nom);
	const string& getPrenom() const;
	void setPrenom(const string& prenom);
	const string& getAdresse() const;
	void setAdresse(const string& adesse);
	const int& getNbAdherent() const;
	const Bibliotheque& getBibliotheque() const;
	void setBibliotheque(const Bibliotheque& biblio);
	const Livre* getLivres() const;
	const int& getMaxEmprunt() const;
	void setMaxEmprunt(const int& seuil);
}
