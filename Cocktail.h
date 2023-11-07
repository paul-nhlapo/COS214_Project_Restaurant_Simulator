#pragma once
#include <string>
#include <iostream>
using namespace std;

class Cocktail
{
private:
    /* data */
public:
    string base;
    string type;
    string ice;
    string fruit;
    Cocktail();
    Cocktail(string base, string type, string ice, string fruit);
    ~Cocktail();
    void printCocktail();
};


