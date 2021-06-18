#ifndef ANIMAL_H
#define ANIMAL_H
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string name;
    int age;
    bool isMale;
    string type;
    
    
    bool isHungry;
    bool isSeek;
    bool isPregnant;
    int dayBeforeBirth;

public:
    string getName();
    string getType();
    bool getSex();
    Animal(string newname, int newage, bool sex, string newtype);
    void setHungry(bool hungry);
};

#endif