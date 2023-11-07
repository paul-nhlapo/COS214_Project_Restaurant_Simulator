#include "Type.h"
#include <string>
#include <vector>
using namespace std;

Type::Type() : AddOn()
{
    this->type = "Type";
}

Type::Type(string x)
{
    this->type = "Type";
    this->name = x;
}

void Type::addInfo(string x)
{
    this->name = x;
}

void Type::addDetail(int ID)
{
}