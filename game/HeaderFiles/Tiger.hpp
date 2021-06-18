#ifndef TIGER_H
#define TIGER_H
#pragma once

#include "Animal.hpp"


class Tiger : public Animal {

public:
    Tiger(string newname, int newage, bool sex);
};

#endif