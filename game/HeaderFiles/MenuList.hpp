#ifndef MENULIST_H
#define MENULIST_H
#pragma once

#include "zoo.hpp"
#include <vector>
#include <iostream>

using namespace std;

class MenuList {
private:
    vector <string> BaseMenuList;
    vector <string> BuySellList;
    /////////////////////////
    vector <string> AnimalList;
    vector <string> SexList;
    //////////////////////////////
    vector <string> BuyEnclosureList;
    ////////////////////////////////
    vector <string> BuyFoodList;
    /////////////////////////
    vector <string> EnclosureList;


    static MenuList *instance;

public:
    MenuList();

    ~MenuList();

    static MenuList *getInstance();

    int baseMenu();

    int buySellMenu();

    int animalType();

    int animalSex();

    int buyEnclosure();

    int sellEnclosure();

    int buyFood();

    int choseEnclosureBuy();

    int choseEnclosureSell();

    int choseEnclosureToSellAnimal();

    void show(vector <string> list);

    void showPlus(vector <string> list);

    int enclosureType();
};

#endif