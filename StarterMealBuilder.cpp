#ifndef STARTERMEALBUILDER_CPP
#define STARTERMEALBUILDER_CPP

#include "StarterMealBuilder.h"
#include "MealProduct.h"

StarterMealBuilder::StarterMealBuilder()
{
}

// StarterMealBuilder::~StarterMealBuilder()
// {
//     delete meal;
// }

void StarterMealBuilder::setMainElement(std::string mainElement)
{
    meal->setMainElement(mainElement);
}

void StarterMealBuilder::setMainElementPrepStrategy(std::string mainElementPrepStrategy)
{
    meal->setCookingStrategy(mainElementPrepStrategy);
}

void StarterMealBuilder::setSideChoice(char choice)
{
    meal->s
}

void StarterMealBuilder::setSideElement(std::string side)
{
    meal->setSide(side);
}


void StarterMealBuilder::setSidePrepStrategy(std::string sidePrepStrategy)
{
    meal->setCookingStrategy(sidePrepStrategy);
}

void StarterMealBuilder::setSauceElement(std::string sauce)
{
    meal->setSauce(sauce);
}

Meal* StarterMealBuilder::getMeal()
{
    return this->meal;
}

#endif
