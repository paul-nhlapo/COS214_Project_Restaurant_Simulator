#ifndef SIMPLEORDER_CPP
#define SIMPLEORDER_CPP

#include "SimpleOrder.h"

Order::Order()
{
    mainElement = "";
    side = "";
    sauce = "";
    cookingMethod = "";
    price = 0.0;
}

std::string Order::getCookingMethod()
{
    return this->cookingMethod;
}

std::string Order::getMainElement()
{
    return this->mainElement;
}

std::string Order::getSauce()
{
    return this->sauce;
}

std::string Order::getSide()
{
    return this->side;
}

#endif