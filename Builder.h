#pragma once
#include <string>
#include <iostream>
#include "Cocktail.h"
using namespace std;

class Builder
{
private:
    /* data */
public:
    Builder(/* args */);
    virtual ~Builder();
    virtual void setBase(string base) = 0;
    virtual void setType(string type) = 0;
    virtual void setIce(string ice) = 0;
    virtual void setFruit(string fruit) = 0;
    virtual Cocktail *getProduct() = 0;
};
