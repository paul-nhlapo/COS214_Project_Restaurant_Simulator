#pragma once
#include "CocktailOrder.h"
#include "AddOn.h"
#include "Base.h"
#include "Type.h"
#include "Ice.h"
#include "Fruit.h"
#include "Bartender.h"
#include <string>
#include <iostream>
using namespace std;

class Bar
{
private:
    /* data */
    Bartender *b1;
public:
    Bar();
    ~Bar();
    void setBarTender(Bartender *b);
    void placeCocktailOrder();
    Cocktail *serve();
};


