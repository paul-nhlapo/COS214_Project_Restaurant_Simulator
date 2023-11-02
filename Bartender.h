#pragma once
#include <string>
#include <iostream>
#include "Cocktail.h"
#include "CocktailMixer.h"
#include "Builder.h"
#include "Order.h"
#include "AddOn.h"
#include "OrderDetail.h"
using namespace std;

class Bartender
{
private:
    Builder *b1;

public:
    Bartender();
    ~Bartender();
    void mix(Order* order);
    Cocktail *getDrink();
    void setBuilder(Builder *b);
};

