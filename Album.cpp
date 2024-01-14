#include "Album.h"

Album::Album() :Livre()
{
	illustration = "";
}

Album::Album(const int& code, const string& auteur, const string& titre, const string& editeur, const string& isbn, const string& public_vise, const string& illu):Livre(code,auteur,titre,editeur,isbn,public_vise)
{
	this->type = ALBUM;
	illustration = illu;
}

const string& Album::getIllustration()
{
	return illustration;
}

void Album::SetIllustration(const string& illustration)
{
	this->illustration = illustration;
}

void Album::affiche()
{
	Livre::affiche();
	cout << "Les ilustrations sont des " << illustration << endl;
}
