#include <iostream>
using namesapce std;
#include "Bibliothèque.h"
#include "Livre.h"

class Adhérent
{
private :
  string nom;
  string prénom;
  string adresse;
  static int nbAdhérent;
  int numAdhérent;
  Blibliothèque bibliothèque;
  Livre* livreEmpruntés;
  int maxEmprunt;
public :
  Adhérent(); //assigne un num d'adhérent
  Adhérent(String n, String p); //avec nom, prémnom
  ~Adhérent();
  void Emprunter(String code);
  void Rendre(Livre livre);
}
