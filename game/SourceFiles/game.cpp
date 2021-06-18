#include "../HeaderFiles/game.hpp"

int day;
int remainingMonth;

void startGame() {
    day = 1;
    remainingMonth = 120;
    updateGame();
}

void updateGame() {

    while (remainingMonth != 0) {
        play();
        while (day != 31) {
            day++;
        }
        day = 1;
        remainingMonth--;
    }
};

void play() {
    clearConsole();
    if (remainingMonth == 120) {
        welcome();
    } else {
        Zoo::update();
        cout << "\nIl reste " << remainingMonth << " mois" << endl;
    }
    menu();
}