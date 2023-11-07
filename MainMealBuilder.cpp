#ifndef MAINMEALBUILDER_CPP
#define MAINMEALBUILDER_CPP

#include "MainMealBuilder.h"
#include "MealProduct.h"

MainMealBuilder::MainMealBuilder()
{
}

MainMealBuilder::~MainMealBuilder()
{

}

void MainMealBuilder::setMainElement(std::string mainElement)
{
    meal->setMainElement(mainElement);
}

void MainMealBuilder::setMainElementPrepStrategy(std::string mainElementPrepStrategy)
{
    meal->setCookingStrategy(mainElementPrepStrategy);
}


void MainMealBuilder::setSideElement(std::string side)
{
    meal->setSide(side);
}


void MainMealBuilder::setSidePrepStrategy(std::string sidePrepStrategy)
{
    meal->setCookingStrategy(sidePrepStrategy);
}

void MainMealBuilder::setSauceElement(std::string sauce)
{
    meal->setSauce(sauce);
}

Meal* MainMealBuilder::getMeal()
{
    return this->meal;
}

#endif