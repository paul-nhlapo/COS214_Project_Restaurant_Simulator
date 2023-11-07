#include "Base.h"
#include <string>
#include <vector>
using namespace std;

Base::Base() : AddOn()
{
    this->type = "Base";
}

Base::Base(string x)
{
    this->type = "Base";
    this->name = x;
}

void Base::addInfo(string x)
{
    this->name = x;
}

void Base::addDetail(int ID)
{
}