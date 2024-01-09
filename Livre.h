#pragma once
#include <iostream>
using namespace std;

enum PublicV { adulte, ados, jeunesses, toutPublic };
enum Etat{libre, emprunté, prêté};

class Livre
{
private:
	string code;
	string auteur;
	string titre;
	string editeur;
	string ISBN;
	PublicV publicVisé;
	Etat état;
};
