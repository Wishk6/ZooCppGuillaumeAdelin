#include "../HeaderFiles/Chicken.hpp"

Chicken::Chicken(string newname, int newage, bool sex) : Animal(newname, newage, sex) {
    if (sex == true) {
        cout << "Vous avez un nouveau Coq ! Son nom est " << newname << " et il a " << newage
             << " mois. Prenez soin de lui !" << endl;
    } else {
        cout << "Vous avez une nouvelle Poule ! Son nom est " << newname << " et elle a " << newage
             << " mois. Prenez soin d'elle !" << endl;
    }
}
