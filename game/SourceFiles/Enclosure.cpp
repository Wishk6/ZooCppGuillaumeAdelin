#include "../HeaderFiles/Enclosure.hpp"

Enclosure::Enclosure(string enclosureName, string enclosureType) : e_name(enclosureName), e_type(enclosureType)
{
    cout << "Nouvel enclos cree !\n " << endl;
}

Enclosure::~Enclosure()
{
}

string Enclosure::getName()
{
    return e_name;
}

string Enclosure::getType()
{
    return e_type;
}

void Enclosure::addAnimal(Animal *animal)
{
    animalList.push_back(animal);
}

void Enclosure::deleteSpecificAnimal(string name, string type)
{
    int price;
    AnimalIterator it = animalList.begin();
    while (it != animalList.end())
    {
        if ((*it)->getName() == name)
        {
            if (type == "Tiger")
            {
                price = 2000;
                Zoo::updateMoney(price);
                cout << green << "L'animal " << name << " a ete vendu pour " << price << " $\n"
                     << white << endl;
                animalList.erase(it);
                return;
            }
            if (type == "Eagle")
            {
                price = 500;
                Zoo::updateMoney(price);
                cout << green << "L'animal " << name << " a ete vendu pour " << price << " $\n"
                     << white << endl;
                animalList.erase(it);
                return;
            }
            if (type == "Chicken")
            {
                price = 10;
                Zoo::updateMoney(price);
                cout << green << "L'animal " << name << " a ete vendu pour " << price << " $\n"
                     << white << endl;
                animalList.erase(it);
                return;
            }
        }
        it++;
    }
    cout << red << "Ce nom ne correspond a aucun animal dans cet enclos.\n"
         << white << endl;
}

void Enclosure::deleteAllAnimals(string type)
{
    int price;
    AnimalIterator it = animalList.begin();
    while (it != animalList.end())
    {
        if (type == "Tiger")
        {
            price = 2000;
            Zoo::updateMoney(price);
            cout << (*it)->getName() << " vendu pour " << price << " $" << endl;
            animalList.erase(it);
            it--;
        }
        if (type == "Eagle")
        {
            price = 500;
            Zoo::updateMoney(price);
            cout << (*it)->getName() << " vendu pour " << price << " $" << endl;
            animalList.erase(it);
            it--;
        }
        if (type == "Chicken")
        {
            price = 10;
            Zoo::updateMoney(price);
            cout << (*it)->getName() << " vendu pour " << price << " $" << endl;
            animalList.erase(it);
            it--;
        }
        it++;
    }
}

void Enclosure::getStealAnimal()
{
    int index = rand() % animalList.size();
    int i = 0;
    AnimalIterator it = animalList.begin();
    while (it != animalList.end())
    {
        if (index == i)
        {
            cout << red << "Il y eu un vol le mois dernier, vous avez perdu le/la " << (*it)->getType() << " nomme " << (*it)->getName() << " situe dans l'enclos " << e_name << "." << white << endl;

            animalList.erase(it);
            delete(*it);
            it--;
        }
        i++;
        it++;
    }
}

vector<string> Enclosure::showAnimals(int enclosureNbr)
{
    vector<string> animalArr;
    int count;
    AnimalIterator it = animalList.begin();

    while (it != animalList.end())
    {
        if ((*it)->getName() != "")
        {
            count++;
            animalArr.push_back((*it)->getName());
            it++;
        }
        else
        {
            cout << "error showing animals" << endl;
        }
    }
    return animalArr;
}

void Enclosure::update()
{
    AnimalIterator it = animalList.begin();
    string animType;
    bool animSex;
    bool hungry;

    while (it != animalList.end())
    {
        animType = (*it)->getType();
        animSex = (*it)->getSex();

        if (animType == "Tiger")
        {
            if (animSex)
            {
                hungry = Zoo::useMeat(12 * 30);
            }
            else
            {
                hungry = Zoo::useMeat(10 * 30);
            }
        }
        if (animType == "Eagle")
        {
            if (animSex)
            {
                hungry = Zoo::useMeat(0.25 * 30);
            }
            else
            {
                hungry = Zoo::useMeat(0.3 * 30);
            }
        }
        if (animType == "Chicken")
        {
            if (animSex)
            {
                hungry = Zoo::useSeed(0.18 * 30);
            }
            else
            {
                hungry = Zoo::useSeed(0.15 * 30);
            }
        }
        if (hungry)
        {
            (*it)->setHungry(hungry);

            cout << blue <<  "L'animal " << (*it)->getName() << " a faim ! " << white << endl;
        }
        it++;
    }
}
