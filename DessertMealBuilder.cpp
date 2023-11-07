#ifndef DESSERTMEALBUILDER_CPP
#define DESSERTMEALBUILDER_CPP

#include "DessertMealBuilder.h"
#include "MealProduct.h"

DessertMealBuilder::DessertMealBuilder()
{
}

DessertMealBuilder::~DessertMealBuilder()
{

}

void DessertMealBuilder::setMainElement(std::string mainElement)
{
    meal->setMainElement(mainElement);
}

void DessertMealBuilder::setMainElementPrepStrategy(std::string mainElementPrepStrategy)
{
    meal->setCookingStrategy(mainElementPrepStrategy);
}


void DessertMealBuilder::setSideElement(std::string side)
{
    meal->setSide(side);
}


void DessertMealBuilder::setSidePrepStrategy(std::string sidePrepStrategy)
{
    meal->setCookingStrategy(sidePrepStrategy);
}

void DessertMealBuilder::setSauceElement(std::string sauce)
{
    meal->setSauce(sauce);
}

Meal* DessertMealBuilder::getMeal()
{
    return this->meal;
}

#endif