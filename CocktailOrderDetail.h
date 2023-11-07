#pragma once
#include <string>
#include <iostream>
#include "CocktailOrder.h"
using namespace std;

class CocktailOrderDetail : public CocktailOrder
{
public:
    CocktailOrderDetail();
    CocktailOrderDetail(int ID);
    void addInfo(string x);
    void addDetail(int ID);
};