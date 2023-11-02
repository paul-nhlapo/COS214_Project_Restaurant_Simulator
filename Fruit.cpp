#include "Fruit.h"
#include <string>
#include <vector>
using namespace std;

Fruit::Fruit() : AddOn()
{
    this->type = "Fruit";
}

Fruit::Fruit(string x)
{
    this->type = "Fruit";
    this->name = x;
}

void Fruit::addInfo(string x)
{
    this->name = x;
}

void Fruit::addDetail(int ID)
{
}