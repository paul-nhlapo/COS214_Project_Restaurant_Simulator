#include "AddOn.h"
#include <string>
#include <vector>
using namespace std;

AddOn::AddOn()
{
    this->nextItem = NULL;
}

AddOn::AddOn(CocktailOrder *nextItem)
{
    this->nextItem = nextItem;
}

void AddOn::setNextItem(CocktailOrder *nI)
{
    this->nextItem = nI;
}

AddOn *AddOn::sp()
{
    return this;
}