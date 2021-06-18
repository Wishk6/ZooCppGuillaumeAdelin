#include "../HeaderFiles/Animal.hpp"

Animal::Animal(string newname, int newage, bool sex, string newtype) : name(newname), age(newage), isMale(sex), type(newtype)
{
}

string Animal::getName()
{
    return name;
}

string Animal::getType()
{
return type;
}

bool Animal::getSex()
{
return isMale;

}
void Animal::setHungry(bool hungry)
{
isHungry = hungry;
}