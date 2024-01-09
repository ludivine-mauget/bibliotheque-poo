#include <iostream>
using namespace std;
#include "Bibliothèque.h"
#include "Livre.h"

class Adherent
{
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
