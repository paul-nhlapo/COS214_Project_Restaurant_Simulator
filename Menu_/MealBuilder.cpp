#ifndef MEALBUILDER_CPP
#define MEALBUILDER_CPP

#include "MealBuilder.h"

MealBuilder::MealBuilder()
{
}

MealBuilder::~MealBuilder() {}

void MealBuilder::setMealType(std::string mealType)
{
    meal->setMealType(mealType);
}

void MealBuilder::setMainElement(std::string mainElement)
{
    meal->setMainElement(mainElement);
}

void MealBuilder::setMainElementPrepStrategy(std::string mainElementPrepStrategy)
{
    meal->setMainPrepStrategy(mainElementPrepStrategy);
}

void MealBuilder::setSideChoice(std::string sideChoice)
{
    meal->setSideChoice(sideChoice);
}

void MealBuilder::setSideElement(std::string side)
{
    meal->setSideElement(side);
}

void MealBuilder::setSideElementPrepStrategy(std::string sidePrepStrategy)
{
    meal->setMainPrepStrategy(sidePrepStrategy);
}

void MealBuilder::setSauceChoice(std::string sauceChoice)
{
    meal->setSauceChoice(sauceChoice);
}

void MealBuilder::setSauceElement(std::string sauce)
{
    meal->setSauceElement(sauce);
}

Meal *MealBuilder::getMeal()
{
    return this->meal;
}

#endif