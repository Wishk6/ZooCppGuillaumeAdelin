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
    cout << yellow << "GG !! You won the game with " << Zoo::getMoney() << "$ !\n" << white << endl;
};

void play() {
    clearConsole();
    if (remainingMonth == 120) {
        welcome();
    } else {
        Zoo::update();
        cout  << blue << "\nIl reste " << remainingMonth << " mois" << blue << endl;
    }
     if (Zoo::getMoney() <= 0) {
        cout << red <<  "Money = " << Zoo::getMoney() << ", you don't have enough money to continue. Retry ! " << white << endl;
        exit;
    }
    menu();
}