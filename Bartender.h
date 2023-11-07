#pragma once
#include <string>
#include <iostream>
#include "Cocktail.h"
#include "CocktailMixer.h"
#include "Builder.h"
#include "CocktailOrder.h"
#include "AddOn.h"
#include "CocktailOrderDetail.h"
using namespace std;

class Bartender
{
private:
    Builder *b1;
    
public:
    Bartender();
    ~Bartender();
    void mix(CocktailOrder *C);
    Cocktail *getDrink();
    void setBuilder(Builder *b);
};
