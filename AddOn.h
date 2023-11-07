#pragma once
#include <string>
#include <iostream>
#include "CocktailOrder.h"
using namespace std;

class AddOn : public CocktailOrder
{
public:
    CocktailOrder *nextItem;
    AddOn();
    AddOn(CocktailOrder *nextItem);
    void addInfo(string x) = 0;
    void addDetail(int ID) = 0;
    void setNextItem(CocktailOrder *nI);
    AddOn *sp();
};