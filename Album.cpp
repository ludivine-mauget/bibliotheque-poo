#include "Album.h"

Album::Album() :Livre()
{
	illustration = BOTH;
    this->type = ALBUM;
}

Album::Album(int code, const string& auteur, const string& titre, const string& editeur, const string& isbn, const string& public_vise, Illu& illu):Livre(code,auteur,titre,editeur,isbn,public_vise)
{
	illustration = illu;
    this->type = ALBUM;
}

const Illu& Album::getIllustration()
{
	return illustration;
}

void Album::SetIllustration(const Illu& illustration)
{
	this->illustration = illustration;
}

void Album::affiche()
{
	Livre::affiche();
	cout << "Les ilustrations sont des " << illustration << endl;
}
