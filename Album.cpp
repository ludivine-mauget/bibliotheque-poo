#include <iostream>
#include "Album.h"

Album::Album(Illu illu) {
    illustrations = illu;
}

Album Album::affiche() {
    Livre::affiche();
    cout<< "L'album est :"<<illustrations<<endl;
}