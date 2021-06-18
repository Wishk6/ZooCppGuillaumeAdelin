#include "../HeaderFiles/MenuList.hpp"
MenuList *MenuList::instance;

MenuList::MenuList() {
    BaseMenuList.push_back("  1-Acheter/Vendre un animal");
    BaseMenuList.push_back("  2-Acheter/Vendre un enclos");
    BaseMenuList.push_back("  3-Acheter de la nourriture");
    BaseMenuList.push_back("  4-Simuler le mois suivant");
    BaseMenuList.push_back("  5-Voir l'etat actuel de mon Zoo");

    BuySellList.push_back("Acheter");
    BuySellList.push_back("Vendre");

    AnimalList.push_back("Tigre");
    AnimalList.push_back("Aigle");
    AnimalList.push_back("Poule");

    SexList.push_back("Male");
    SexList.push_back("Femelle");

    BuyFoodList.push_back("Viande");
    BuyFoodList.push_back("Graine");
}

MenuList::~MenuList() {
}

MenuList *MenuList::getInstance() {
    if (instance == nullptr) {
        instance = new MenuList();
    }
    return instance;
}

int MenuList::baseMenu() {
    cout << cyan << "Que voulez-vous faire?\n" << white 
         << endl;
    for (size_t i = 0; i < BaseMenuList.size(); i++) {
        cout << BaseMenuList.at(i) << endl;
    }
    return BaseMenuList.size();
}

int MenuList::buySellMenu() {
    cout << cyan << "Voulez-vous acheter ou vendre?\n"
         << white << endl;
    show(BuySellList);
    return BuySellList.size() + 1;
}

int MenuList::animalType() {
    cout << cyan << "Quel animal voulez-vous acheter?\n"
         << white << endl;
    show(AnimalList);
    return AnimalList.size() + 1;
}

int MenuList::animalSex() {
    cout << cyan << "Choisissez son sexe :\n"
         << white << endl;
    show(SexList);
    return SexList.size() + 1;
}

int MenuList::enclosureType() {
    cout << cyan << "Quel type d'enclos voulez-vous acheter ?\n"
         << white << endl;
    show(AnimalList);
    return AnimalList.size() + 1;
}

int MenuList::buyFood() {
    cout << cyan << "Quel type de nourriture voulez-vous acheter?" << white << endl;
    show(BuyFoodList);
    return BuyFoodList.size() + 1;
}

int MenuList::choseEnclosureBuy() {
    cout << cyan << "Dans quel enclos voulez-vous le mettre?\n"
         << white << endl;
    EnclosureList = Zoo::getEnclosureList();
    show(EnclosureList);
    return EnclosureList.size() + 1;
}

int MenuList::choseEnclosureSell() {
    cout << cyan << "Quel enclos voulez-vous vendre?\n"
         << red << "ATTENTION!\n" << white 
         << "Ne vendez pas un enclos avec des animaux a l'interieur, ou ils disparaitrons \n"
         << endl;
    EnclosureList = Zoo::getEnclosureList();
    show(EnclosureList);
    return EnclosureList.size() + 1;
}

int MenuList::choseEnclosureToSellAnimal() {
    cout << cyan << "Dans quel enclos est l'animal que vous voulez vendre ?\n"
         << white << endl;
    EnclosureList = Zoo::getEnclosureList();
    show(EnclosureList);
    return EnclosureList.size() + 1;
}

// int MenuList::choseAnimal()
// {
// cout << "Quel animal voulez-vous vendre ?\n" << endl;

//    

// }

void MenuList::show(vector <string> list) {
    string toAdd = "  ";
    string retour;
    retour = "  ";
    retour = "Retour";
    list.push_back(retour);
    for (size_t i = 0; i < list.size(); i++) {
        toAdd += to_string(i + 1) + "-";
        cout << toAdd << list.at(i) << endl;
        toAdd = "  ";
    }
}
