#include "../HeaderFiles/Tiger.hpp"

Tiger::Tiger(string newname, int newage, bool sex, string newtype) : Animal(newname, newage, sex, newtype) {
    if (sex == true) {
        cout << "Vous avez un nouveau tigre ! Son nom est " << newname << " et il a " << newage
             << " mois. Prenez soin de lui !" << endl;
    } else {
        cout << "Vous avez une nouvelle tigresse ! Son nom est " << newname << " et elle a " << newage
             << " mois. Prenez soin d'elle !" << endl;
    }
}