#ifndef EAGLE_H
#define EAGLE_H
#pragma once

#include "Animal.hpp"

using namespace std;

class Eagle : public Animal {

public:
    Eagle(string newname, int newage, bool sex);
};

#endif