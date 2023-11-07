#include "CocktailOrder.h"
#include <string>
#include <vector>
using namespace std;

CocktailOrder::CocktailOrder()
{
    this->ID = -1;
    this->name = "";
    this->type = "";
}

CocktailOrder::CocktailOrder(int ID)
{
    this->ID = ID;
    this->name = "";
    this->type = "";
}