/*
    Dessert Chef Implementation file
*/
#ifndef DESSERTCHEF_CPP
#define DESSERTCHEF_CPP

#include "DessertChef.h"

DessertChef::DessertChef(std::string name) : Chef(name)
{
    this->chefType = "Dessert Course Chef";
}

void DessertChef::receiveOrder()
{

}

void DessertChef::sendOrder()
{
    
}

std::string DessertChef::getChefType()
{
    return this->chefType;
}

void DessertChef::prepareMeal(std::string mealType)
{
    if(mealType == "Dessert")
    {
        std::cout << "Dessert Chef is preparing this meal";
    }

    else
    {
        std::cout << this->getChefType() << " passing meal on" << std::endl;
        nextChef->prepareMeal(mealType);
    }
}

void DessertChef::setNextChef(Chef* nextChef)
{
    this->nextChef = nextChef;
}

#endif