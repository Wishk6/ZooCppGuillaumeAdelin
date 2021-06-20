#ifndef ENCLOSURE_H
#define ENCLOSURE_H
#pragma once

#include <vector>
#include "Animal.hpp"

using namespace std;

typedef vector<Animal *> AnimalList;
typedef AnimalList::iterator AnimalIterator;

class Enclosure {
private:
    string red = "\033[31m";
    string green = "\033[32m";
    string white = "\033[37m";
    string e_name;
    string e_type;
    vector<Animal *> animalList;

public:
    Enclosure(string enclosureName, string enclosureType);

    ~Enclosure();

    string getName();

    string getType();

    void addAnimal(Animal *animal);

    void deleteSpecificAnimal(string name, string type);

    void deleteAllAnimals(string type);

    void getStealAnimal();

    vector <string> showAnimals(int enclosureNbr);
    
    void update();


};

#include "zoo.hpp"
// pour qu'il connaisse Zoo mais qu'il y ait pas de forcard delcaration

#endif