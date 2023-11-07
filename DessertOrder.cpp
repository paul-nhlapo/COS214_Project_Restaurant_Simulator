#ifndef DESSERTORDER_CPP
#define DESSERTORDER_CPP

#include "DessertOrder.h"

DessertOrder::DessertOrder(std::string mainElement, std::string cookingMethod, std::string side, std::string sauce)
{
    this->mainElement = mainElement;
    this->cookingMethod = cookingMethod;
    this->side = side;
    this->sauce = sauce;

    this->orderType = "Dessert";
    this->price = 75.0;
}

std::string DessertOrder::getOrderType()
{
    return this->orderType;
}

#endif