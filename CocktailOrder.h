#pragma once
#include <string>
#include <iostream>
using namespace std;

class CocktailOrder
{
public:
    string type;
    string name;
    int ID;
    CocktailOrder();
    CocktailOrder(int ID);
    virtual void addInfo(string x) = 0;
    virtual void addDetail(int ID) = 0;
};