#include "../HeaderFiles/Enclosure.hpp"

Enclosure::Enclosure(string enclosureName, string enclosureType) : e_name(enclosureName), e_type(enclosureType) {
    cout << "Nouvel enclos cree !\n " << endl;
}

Enclosure::~Enclosure() {
}

string Enclosure::getName() {
    return e_name;
}

string Enclosure::getType() {
    return e_type;
}

void Enclosure::addAnimal(Animal *animal) {
    animalList.push_back(animal);
}

void Enclosure::deleteSpecificAnimal(string name, string type) {
    int price;
    AnimalIterator it = animalList.begin();
    while (it != animalList.end()) {
        if ((*it)->getName() == name) {
            if (type == "Tiger") {
                price = 2000;
                Zoo::updateMoney(price);
                cout << green << "L'animal " << name << " a ete vendu pour " << price << " $\n"
                     << white << endl;
                animalList.erase(it);
                return;
            }
            if (type == "Eagle") {
                price = 500;
                Zoo::updateMoney(price);
                cout << green << "L'animal " << name << " a ete vendu pour " << price << " $\n"
                     << white << endl;
                animalList.erase(it);
                return;
            }
            if (type == "Chicken") {
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

void Enclosure::deleteAllAnimals(string enclosureName, string type) {
    int price;
    AnimalIterator it = animalList.begin();
    while (it != animalList.end()) {
        if (type == "Tiger") {
            price = 2000;
            Zoo::updateMoney(price);
            cout << (*it)->getName() << " vendu pour " << price << " $" << endl;
            animalList.erase(it);
            it--;
        }
        if (type == "Eagle") {
            price = 500;
            Zoo::updateMoney(price);
            cout << (*it)->getName() << " vendu pour " << price << " $" << endl;
            animalList.erase(it);
            it--;
        }
         if (type == "Chicken") {
            price = 10;
            Zoo::updateMoney(price);
            cout << (*it)->getName() << " vendu pour " << price << " $" << endl;
            animalList.erase(it);
            it--;
        }
        it++;
    }
}

vector <string> Enclosure::showAnimals(int enclosureNbr) {
    vector <string> animalArr;
    int count;
    AnimalIterator it = animalList.begin();

    while (it != animalList.end()) {
        if ((*it)->getName() != "") {
            count++;
            animalArr.push_back((*it)->getName());
            it++;
        } else {
            cout << "error showing animals" << endl;
        }
    }
    return animalArr;
}

// void Enclosure::update()
// {
//     AnimalIterator it = animalList.begin();
//     bool isAlive;
//     while (it != animalList.end())
//     {
//         isAlive = (*it)->update();
//         if (!isAlive)
//         {
//             cout << "L'animal " << (*it)->getName() << " situe dans l'enclos "<< e_name << " est mort" << endl;
//             deleteAnimal((*it)->getName());
//             it--;
//         }
//         it++;
//     }
// }
