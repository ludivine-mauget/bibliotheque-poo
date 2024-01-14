#pragma once
#include "Livre.h"
using namespace std;

enum Illu {photo, dessin, both};

class Adherent : public Livre {
    private:
        Illu illustrations;
    public :
        Adherent(Illu);
        Adherent affiche();
};
