/*
    Starter Chef Implementation file
*/
#ifndef STARTERCHEF_CPP
#define STARTERCHEF_CPP

#include "StarterChef.h"

StarterChef::StarterChef(std::string name) : Chef(name)
{
    this->chefType = "Starter Course Chef";
}

void StarterChef::receiveOrder()
{

}

void StarterChef::sendOrder()
{

}

std::string StarterChef::getChefType()
{
    return this->chefType;
}

void StarterChef::prepareMeal(std::string mealType)
{
    if(mealType == "Starter")
    {
        std::cout << this->getChefType() <<" is preparing this meal";
    }

    else
    {
        std::cout << this->getChefType() << " passing meal on" << std::endl;
        nextChef->prepareMeal(mealType);
    }
}

void StarterChef::setNextChef(Chef* nextChef)
{
    this->nextChef = nextChef;
}

#endif