#include <iostream>
<<<<<<< HEAD
<<<<<<< HEAD:adherent.h
using namespace std;
#include "Bibliothèque.h"
=======
using namesapce std;
=======
using namespace std;
>>>>>>> b890b1ceab0214d3df95a5c830ab7c8c42548353
#include "Bibliotheque.h"
>>>>>>> 719fad0ce36091a60d2f8f04bfa16bbd037fa11d:Adherent.h
#include "Livre.h"

class Adherent
{
<<<<<<< HEAD
private :
  string nom;
  string prenom;
  string adresse;
  static int nbAdherent;
  int numAdherent;
  Bibliotheque bibliotheque;
  Livre* livreEmpruntes;
  int maxEmprunt;
public :
  Adherent(); //assigne un num d'adhérent
  Adherent(String n, String p); //avec nom, prémnom
  ~Adherent();
  void Emprunter(String code);
  void Rendre(Livre livre);
};
=======
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
>>>>>>> b890b1ceab0214d3df95a5c830ab7c8c42548353
