#include "CocktailMixer.h"
#include <string>
#include <vector>
using namespace std;

CocktailMixer::CocktailMixer(/* args */)
{
    this->res = new Cocktail();
}

CocktailMixer::~CocktailMixer()
{
    delete this->res;
}

void CocktailMixer::setBase(string base)
{
    this->res->base = base;
}

void CocktailMixer::setType(string type)
{
    this->res->type = type;
}

void CocktailMixer::setIce(string ice)
{
    this->res->ice = ice;
}

void CocktailMixer::setFruit(string fruit)
{
    this->res->fruit = fruit;
}

Cocktail *CocktailMixer::getProduct()
{
    return this->res;
}
