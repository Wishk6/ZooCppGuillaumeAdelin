#include "../HeaderFiles/zoo.hpp"

using namespace std;

double Zoo::meat = 0;
double Zoo::seed = 0;
double Zoo::money = 0;
vector<Enclosure *> Zoo::my_EnclosList;

Zoo::Zoo()
{
}

void Zoo::updateMoney(int profit)
{
    money += profit;
}

vector<Enclosure *> Zoo::getEnclosurelistForIt()
{
    return my_EnclosList;
}

void Zoo::init()
{
    // Tiger
    buyEnclosure("EnclosTigre1", "Tiger");
    buyEnclosure("EnclosTigre2", "Tiger");
    buyAnimal("EnclosTigre1", "Tiger", "Tiger1Male", true);
    buyAnimal("EnclosTigre1", "Tiger", "Tiger2Female", false);
    buyAnimal("EnclosTigre2", "Tiger", "Tiger3Male", true);
    buyAnimal("EnclosTigre2", "Tiger", "Tiger4Female", false);
    // Eagle
    buyEnclosure("EnclosAigle1", "Eagle");
    buyAnimal("EnclosAigle1", "Eagle", "Eagle1Male", true);
    buyAnimal("EnclosAigle1", "Eagle", "Eagle2Female", false);
    buyAnimal("EnclosAigle1", "Eagle", "Eagle3Male", true);
    buyAnimal("EnclosAigle1", "Eagle", "Eagle4Female", false);
    // Chicken
    buyEnclosure("EnclosPoulet1", "Chicken");
    buyAnimal("EnclosPoulet1", "Chicken", "ChickenFemale1", false);
    buyAnimal("EnclosPoulet1", "Chicken", "ChickenFemale2", false);
    buyAnimal("EnclosPoulet1", "Chicken", "ChickenFemale3", false);
    buyAnimal("EnclosPoulet1", "Chicken", "ChickenFemale4", false);
    buyAnimal("EnclosPoulet1", "Chicken", "ChickenFemale5", false);
    buyAnimal("EnclosPoulet1", "Chicken", "ChickenFemale6", false);
    buyAnimal("EnclosPoulet1", "Chicken", "ChickenFemale7", false);
    buyAnimal("EnclosPoulet1", "Chicken", "ChickenFemale8", false);
    buyAnimal("EnclosPoulet1", "Chicken", "ChickenFemale9", false);
    buyAnimal("EnclosPoulet1", "Chicken", "ChickenMale1", true);
    money = 80000;
    meat = 10000;
    seed = 500;
}

void Zoo::status()
{
    EnclosureIterator it = my_EnclosList.begin();
    int enclosureNbr;
    vector<string> animalList;
    cout << green << "\nVous avez actuellement " << money << " $.\nIl vous reste " << meat
         << " kilos de viande et " << seed << " kilos de graine.\nVotre zoo compte " << my_EnclosList.size()
         << " enclos !" << white
         << endl;
    while (it != my_EnclosList.end())
    {
        for (size_t i = 0; i < getEnclosureList().size(); i++)
        {
            std::cout << "\nL'enclos " << getEnclosureList()[i] << " contient :\n"
                      << std::endl;
            animalList = (*it)->showAnimals(enclosureNbr);

            for (size_t j = 0; j < animalList.size(); j++)
            {
                cout << animalList[j] << "\t";
            }
            cout << white << "\n"
                 << endl;
            enclosureNbr++;
            it++;
        }
    }
}

void Zoo::buyEnclosure(string name, string type)
{
    if (type == "Tiger")
    {
        my_EnclosList.push_back(new Enclosure(name, type));
        money -= 2000;
    }
    if (type == "Eagle")
    {
        my_EnclosList.push_back(new Enclosure(name, type));
        money -= 2000;
    }
    if (type == "Chicken")
    {
        my_EnclosList.push_back(new Enclosure(name, type));
        money -= 300;
    }
}

void Zoo::sellEnclosure(string name)
{
    int price;
    EnclosureIterator it = my_EnclosList.begin();
    while (it != my_EnclosList.end())
    {
        if ((*it)->getName() == name)
        {
            if ((*it)->getType() == "Tiger" || (*it)->getType() == "Eagle")
            {
                price = 500;
                money += price;
            }
            if ((*it)->getType() == "Chicken")
            {
                price = 50;
                money += price;
            }
            (*it)->deleteAllAnimals(name, (*it)->getType()); //delete all anim

            cout << (*it)->getName() << " vendu avec succes pour " << price << " $ !\n " << endl;

            my_EnclosList.erase(it);
            return;
        }
        it++;
    }
}

void Zoo::buyAnimal(string enclosureName, string type, string name, bool sex)
{
    EnclosureIterator it = my_EnclosList.begin();

    while (it != my_EnclosList.end())
    {
        if ((*it)->getName() == enclosureName)
        {
            (*it)->addAnimal(createAnimal(type, name, sex));
            cout << "\nAnimal ajoute dans l'enclos \"" << (*it)->getName() << "\"\n"
                 << endl;
        }
        it++;
    }
}

void Zoo::sellAnimal(string enclosureName, string name)
{
    string type;
    EnclosureIterator it = my_EnclosList.begin();
    while (it != my_EnclosList.end())
    {
        if ((*it)->getName() == enclosureName)
        {
            if ((*it)->getType() == "Tiger")
            {
                type = "Tiger";
                (*it)->deleteSpecificAnimal(name, type);
            }
            if ((*it)->getType() == "Eagle")
            {
                type = "Eagle";
                (*it)->deleteSpecificAnimal(name, type);
            }
            if ((*it)->getType() == "Chicken")
            {
                type = "Chicken";
                (*it)->deleteSpecificAnimal(name, type);
            }
        }
        it++;
    }
}

void Zoo::buyMeat(double quantity)
{
    meat += quantity;
    money -= quantity * 5;
    cout << "\nVous avez achete " << quantity << "kg de viande\n"
         << endl;
}

void Zoo::buySeed(double quantity)
{
    seed += quantity;
    money -= quantity * 2.5;
    cout << "\nVous avez achete " << quantity << "kg de graine\n"
         << endl;
}

Animal *Zoo::createAnimal(string type, string name, bool sex)
{
    Animal *animal = NULL;
    if (type == "Tiger")
    {
        animal = new Tiger(name, 6, sex,type);
        money -= 3000;
    }
    if (type == "Eagle")
    {
        animal = new Eagle(name, 6, sex, type);
        money -= 1000;
    }
    if (type == "Chicken")
    {
        animal = new Chicken(name, 6, sex, type);
        money -= 20;
    }
    return animal;
}

vector<string> Zoo::getEnclosureList()
{
    EnclosureIterator it = my_EnclosList.begin();
    vector<string> enclosureList;

    while (it != my_EnclosList.end())
    {
        string enclosureName = (*it)->getName();
        enclosureList.push_back(enclosureName);
        it++;
    }
    return enclosureList;
}


void Zoo::update()
{

    EnclosureIterator it = my_EnclosList.begin();

    while (it != my_EnclosList.end())
    {
        (*it)->update();
        it++;
    }
}

void Zoo::useMeat(double quantity)
{
    meat -= quantity;
}

void Zoo::useSeed(double quantity)
{
    seed -= quantity;
}
