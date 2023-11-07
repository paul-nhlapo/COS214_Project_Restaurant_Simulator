#ifndef STARTERORDER_CPP
#define STARTERORDER_CPP

#include "StarterOrder.h"

StarterOrder::StarterOrder(std::string mainElement, std::string cookingMethod, std::string side, std::string sauce)
{
    this->mainElement = mainElement;
    this->cookingMethod = cookingMethod;
    this->side = side;
    this->sauce = sauce;

    this->orderType = "Starter";
    this->price = 50.0;
}

std::string StarterOrder::getOrderType()
{
    return this->orderType;
}

#endif