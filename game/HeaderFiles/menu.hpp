#ifndef MENU_H
#define MENU_H
#pragma once

#include <iostream>
#include <vector>
#include "MenuList.hpp"
#include "Enclosure.hpp"
#include "Zoo.hpp"

using namespace std;

int verifyInput(string choice, int size);

int getInput(int size);

void menu();

void buySellAnimal();

void choseAnimalType();

void choseAnimalSex(string type);

void choseAnimalEnclosure(string type, bool sex);

void choseEnclosureToSellAnimal();

void sellAnimalMenu(string enclosureName);

void buySellEnclosure();

void sellEnclosure();

void choseEnclosureType();

void choseEnclosureName(string type);

void buyFood();

void getZooStatus();

#endif