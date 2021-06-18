#include "../HeaderFiles/init.hpp"
#include "../HeaderFiles/os.hpp"

using namespace std;

void welcome() {
    cout << red << "\nWelcome in ZooSimulator\n" << white
         << endl;
    cout << "\nVous commencez le jeu avec :\n-80 000$ \n-2 enclos de tigre comprenant chacun un couple de tigres"
         << "\n-Un enclos d'aigles incluant 2 couples d'aigles " << endl;
}

void initGame() {
    Zoo::init();

    clearConsole();
    welcome();

    startGame();
}
