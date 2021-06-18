#ifndef ZOO_H
#define ZOO_H

#include "Enclosure.hpp"
#include "Tiger.hpp"
#include "Eagle.hpp"
#include "Chicken.hpp"
#include "os.hpp"
#include "Animal.hpp"
#include "color.hpp"

#include <iostream>
#include <vector>

typedef vector<Enclosure *> EnclosureList;
typedef EnclosureList::iterator EnclosureIterator;

class Zoo {
    static double meat;
    static double seed;
    static double money;
    static vector<Enclosure *> my_EnclosList;

public:
    Zoo();

    static void init();

    static void updateMoney(int profit);

    static vector<Enclosure *> getEnclosurelistForIt();

    static void status();

    static void buyEnclosure(string name, string type);

    static void sellEnclosure(string name);

    static void buyAnimal(string Enclosurename, string type, string name, bool sex);

    static void sellAnimal(string Enclosurename, string name);

    static void buyMeat(double quantity);

    static void buySeed(double quantity);

    static Animal *createAnimal(string type, string name, bool sex);

    static vector <string> getEnclosureList();

    // static void update();
    static void useMeat(double quantity);

    static void useSeed(double quantity);
};

#endif // ZOO_H