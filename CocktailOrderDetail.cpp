#include "CocktailOrderDetail.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

CocktailOrderDetail::CocktailOrderDetail() : CocktailOrder()
{
    this->type = "Detail";
}

CocktailOrderDetail::CocktailOrderDetail(int ID) : CocktailOrder(ID)
{
    this->type = "Detail";
}

void CocktailOrderDetail::addDetail(int ID)
{
    this->ID = ID;
}

void CocktailOrderDetail::addInfo(string x)
{
    return;
}