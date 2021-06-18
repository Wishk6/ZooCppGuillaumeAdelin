#include "../HeaderFiles/Animal.hpp"

Animal::Animal(string newname, int newage, bool sex) : name(newname), age(newage), isMale(sex) {
}

string Animal::getName() {
    return name;
}
