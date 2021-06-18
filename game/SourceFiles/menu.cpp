#include "../HeaderFiles/menu.hpp"

vector<string> enclosureList;
string choice;
int input;
int sizeList;
MenuList *List;
bool endMonth;

int verifyInput(string choice, int sizeList)
{
    try
    {
        stoi(choice);
    }
    catch (const std::exception &e)
    {
        cout << "Veuillez Rentrer un chiffre valide :\n";
        return 0;
    }

    int number = stoi(choice);
    if (number > 0 && number <= sizeList)
    {
        return number;
    }
    if (sizeList == 0)
    {
        return number;
    }
    cout << "Veuillez Rentrer un chiffre valide :\n";

    return 0;
}

int getInput(int sizeList)
{
    input = 0;

    while (input == 0)
    {
        cin >> choice;
        input = verifyInput(choice, sizeList);
    }
    return input;
}

void menu()
{
    List = MenuList::getInstance();
    cout << "\n";
    endMonth = false;
    while (!endMonth)
    {
        sizeList = List->baseMenu();

        input = getInput(sizeList);
        switch (input)
        {
        case 1:
            buySellAnimal();
            break;
        case 2:
            buySellEnclosure();
            break;
        case 3:
            buyFood();
            break;
        case 4:
            endMonth = true;
            break;
        case 5:
            getZooStatus();
            break;
        default:
            return;
        }
    }
}

void buySellAnimal()
{
    sizeList = List->buySellMenu();
    input = getInput(sizeList);
    if (input == 1)
    {
        choseAnimalType();
        return;
    }
    if (input == 2)
    {
        choseEnclosureToSellAnimal();
        return;
    }
    if (input == 3)
    {
        menu();
        return;
    }
}

void choseAnimalType()
{
    sizeList = List->animalType();
    input = getInput(sizeList);
    if (input == 1)
    {
        choseAnimalSex("Tiger");
        return;
    }
    if (input == 2)
    {
        choseAnimalSex("Eagle");
        return;
    }
    if (input == 3)
    {
        choseAnimalSex("Chicken");
        return;
    }
    if (input == 4)
    {
        buySellAnimal();
        return;
    }
}

void choseAnimalSex(string type)
{
    sizeList = List->animalSex();
    input = getInput(sizeList);
    if (input == 1)
    {
        choseAnimalEnclosure(type, true);
        return;
    }
    if (input == 2)
    {
        choseAnimalEnclosure(type, false);
        return;
    }
    if (input == 3)
    {
        choseAnimalType();
        return;
    }
}

void choseAnimalEnclosure(string type, bool sex)
{

    sizeList = List->choseEnclosureBuy();
    enclosureList = Zoo::getEnclosureList();
    string enclosureName;
    input = getInput(sizeList);

    vector<Enclosure *> enclosureListObj = Zoo::getEnclosurelistForIt();
    EnclosureIterator it = enclosureListObj.begin();
    string enclosureType;
     
    if (input < sizeList)
    {
        enclosureName = enclosureList.at(input - 1);
       
        while (it != enclosureListObj.end()) // return list of animals
        {
        if ((*it)->getName() == enclosureName)
        {
            enclosureType = (*it)->getType();
        }
        it++;
        }
    }
     else
    {
        choseAnimalSex(type);
        return;
    }    
   
     

    if (enclosureType != type ) {
        cout << red << "Cet enclos ne peut pas accueillir un animal de ce type. " << white << endl;
        choseAnimalSex(type);
        return;
    }
   
 Zoo::getEnclosurelistForIt();
    cout << "Donnez lui un nom:\n";
    string name;
    cin >> name;
    cout << "\n";
    Zoo::buyAnimal(enclosureName, type, name, sex);
}

void choseEnclosureToSellAnimal()
{
    sizeList = List->choseEnclosureToSellAnimal();
    enclosureList = Zoo::getEnclosureList(); //  affiche un vec<string>
    vector<Enclosure *> enclosureIterator;
    string enclosureName;

    input = getInput(sizeList);

    if (input < sizeList)
    {
        enclosureName = enclosureList.at(input - 1);
        sellAnimalMenu(enclosureName);
    }
    else
    {
        buySellAnimal();
        return;
    }
}

void sellAnimalMenu(string enclosureName)
{

    vector<string> my_animalList;
    int count;
    vector<Enclosure *> enclosureListObj = Zoo::getEnclosurelistForIt();
    EnclosureIterator it = enclosureListObj.begin();

    cout << "Quel animal voulez-vous vendre ? \n"
         << endl;

    while (it != enclosureListObj.end()) // return list of animals
    {
        if ((*it)->getName() == enclosureName)
        {

            my_animalList = ((*it)->showAnimals(count));
            count++;
        }
        it++;
    }

/////////////////////////////

    for (size_t i = 0; i < my_animalList.size(); i++) // print la list
    {
        std::cout << "  " << count << "-" << my_animalList[i] << std::endl;
        count++;
    }
    cout << "  " << count << "-Retour" << endl;

    size_t animalNbr;
    cin >> animalNbr;

    if (animalNbr > my_animalList.size() + 1)
    {
        cout << red << "Ce chiffre ne correspond a aucun animal" << white << endl;
    }
    if (animalNbr == my_animalList.size() + 1) // gere le -Retour
    {
        choseEnclosureToSellAnimal();
    }
    for (size_t i = 0; i <= my_animalList.size(); i++) // compare
    {
        if (i == animalNbr)
        {
            Zoo::sellAnimal(enclosureName, my_animalList[i - 1]);
            break;
        }
    }
}

void buySellEnclosure()
{
    sizeList = List->buySellMenu();
    input = getInput(sizeList);
    if (input == 1)
    {
        choseEnclosureType();
        return;
    }
    if (input == 2)
    {
        sellEnclosure();
        return;
    }
    if (input == 3)
    {
        menu();
    }
}

void sellEnclosure()
{
    sizeList = List->choseEnclosureSell();
    enclosureList = Zoo::getEnclosureList();
    string enclosureToSell;
    input = getInput(sizeList);

    if (input < sizeList)
    {
        enclosureToSell = enclosureList.at(input - 1);
    }
    else
    {
        buySellEnclosure();
        return;
    }
    Zoo::sellEnclosure(enclosureToSell);
}

void choseEnclosureType()
{
    sizeList = List->enclosureType();
    input = getInput(sizeList);
    string type;
    string name;
    if (input == 1)
    {
        type = "Tiger";
    }
    if (input == 2)
    {
        type = "Eagle";
    }
    if (input == 3)
    {
        type = "Chicken";
    }
    if (input == 4)
    {
        buySellEnclosure();
        return;
    }
    choseEnclosureName(type);
}

void choseEnclosureName(string type)
{
    cout << "Donnez un nom a votre enclos \033[31m(NE PAS METTRE D'ESPACE) :\033[37m  \n";
    string name;
    cin >> name;
    Zoo::buyEnclosure(name, type);
}

void buyFood()
{
    sizeList = List->buyFood();
    input = getInput(sizeList);
    if (input == 1)
    {
        cout << "Quelle quantitee de viande voulez-vous acheter?\n";
        input = getInput(0);
        Zoo::buyMeat(input);
    }
    if (input == 2)
    {
        cout << "Quelle quantitee de graine voulez-vous acheter?\n";
        input = getInput(0);
        Zoo::buySeed(input);
    }
}

void getZooStatus()
{
    Zoo::status();
}
