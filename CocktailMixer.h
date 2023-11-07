#pragma once
#include <iostream>
#include <string>
#include "Builder.h"
#include "Cocktail.h"
using namespace std;

class CocktailMixer:public Builder
{
private:
    Cocktail *res;
public:
    CocktailMixer(/* args */);
    ~CocktailMixer();
    void setBase(string base);
    void setType(string type);
    void setIce(string ice);
    void setFruit(string fruit);
    Cocktail *getProduct();
};



