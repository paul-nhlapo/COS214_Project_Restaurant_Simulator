#include "Cocktail.h"
#include <string>
#include <vector>
using namespace std;

Cocktail::Cocktail(/* args */)
{
    this->base = "";
    this->type = "";
    this->ice = "";
    this->fruit = "";
}

Cocktail::Cocktail(string base, string type, string ice, string fruit)
{
    this->base = base;
    this->type = type;
    this->ice = ice;
    this->fruit = fruit;
}

Cocktail::~Cocktail()
{
}

void Cocktail::printCocktail()
{
    cout << this->base << " based " << this->type << " Cocktail with " << this->ice << " ice, flavoured with " << this->fruit << endl;
}