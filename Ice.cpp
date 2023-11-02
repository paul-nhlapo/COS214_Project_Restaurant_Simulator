#include "Ice.h"
#include <string>
#include <vector>
using namespace std;

Ice::Ice() : AddOn()
{
    this->type = "Ice";
}

Ice::Ice(string x)
{
    this->type = "Ice";
    this->name = x;
}

void Ice::addInfo(string x)
{
    this->name = x;
}

void Ice::addDetail(int ID)
{
}