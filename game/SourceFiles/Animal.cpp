#include "../HeaderFiles/Animal.hpp"

Animal::Animal(string newname, int newage, bool sex, string newtype) : name(newname), age(newage), isMale(sex), type(newtype) {

}

string Animal::getName() {
    return name;
}

bool Animal::update() {

int death = rand() % 100 + 1;
cout << death << endl;
age+=1;
cout << age << endl;
return true;
}