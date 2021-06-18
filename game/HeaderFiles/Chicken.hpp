#ifndef CHICKEN_H
#define CHICKEN_H
#pragma once

#include "Animal.hpp"

using namespace std;

class Chicken : public Animal {

public:
    Chicken(string newname, int newage, bool sex, string newtype);
};

#endif