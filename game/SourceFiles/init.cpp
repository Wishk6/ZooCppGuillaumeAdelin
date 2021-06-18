#include "../HeaderFiles/init.hpp"
#include "../HeaderFiles/os.hpp"

using namespace std;

void welcome()
{
    cout << red << "\nWelcome in ZooSimulator\n"
         << white
         << endl;
    cout << "\nVous commencez le jeu avec :\n-80 000$"
         << "\n-2 enclos de tigre comprenant chacun un couple de tigres"
         << "\n-Un enclos d'aigles incluant 2 couples d'aigles "
         << "\n-Un enclos de poules incluant 10 poules et un coq\n"
         << red << "\nNe passez pas un mois avec un portefeuille inferieur ou egal a 0$, ou votre Zoo sera saisi !\n"
         << white
         << green << "\nVotre Objectif est de finir le jeu avec le plus d'argent possible, bonne chance !"
         << white << endl;
}

void initGame()
{
    Zoo::init();

    clearConsole();
    welcome();

    startGame();
}
