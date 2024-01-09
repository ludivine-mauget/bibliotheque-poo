#pragma once
#include "Livre.h"
using namespace std;

enum Illu {photo, dessin, both};

class Album : public Livre {
    private:
        Illu illustrations;
    public :
        Album(Illu);
        Album affiche();
};
