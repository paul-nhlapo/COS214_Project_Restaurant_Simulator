/*
#ifndef MEAL_CPP
#define MEAL_CPP

#include "MealProduct.h"

Meal::Meal()
{

}

std::string Meal::getMainElement()
{
    return this->mainElement;
}

std::string Meal::getSide()
{
    return this->side;
}

std::string Meal::getSauce()
{
    return this->sauce;
}

std::string Meal::getCookingStrategy()
{
    return this->cookingStrategy;
}

void Meal::setMainElement(std::string mainElement)
{
    this->mainElement = mainElement;
}

void Meal::setCookingStrategy(std::string prepStrategy)
{
    this->cookingStrategy = prepStrategy;
}

void Meal::setSide(std::string side)
{
    this->side = side;
}

void Meal::setSauce(std::string sauce)
{
    this->sauce = sauce;
}

std::string Meal::printMeal()
{
    std::string meal = "";

    meal += this->getCookingStrategy() + " " + this->getMainElement();

    if(this->getSide() != "")
    {
        meal += "with " + this->getSide();
    }

    if(this->getSauce() != " ")
    {
        meal += "and a " + this->getSauce();
    }

    return meal;
}

#endif
*/

#ifndef MEAL_CPP
#define MEAL_CPP

#include "MealProduct.h"

Meal::Meal()
{}

void Meal::setMealType(std::string mealType)
{
    this->mealType = mealType;
}

void Meal::setMainElement(std::string mainElement)
{
    this->mainElement = mainElement;
}

void Meal::setMainPrepStrategy(std::string mainPrepStrategy)
{
    this->mainPrepStrategy = mainPrepStrategy;
}

void Meal::setSideChoice(std::string sideChoice)
{
    if(sideChoice == "")
        this->sidesChoice = 'N';
    else
        this->sidesChoice = 'Y';
}

void Meal::setSideElement(std::string sideElement)
{
    this->sidesElement = sideElement;
}

void Meal::setSauceChoice(std::string sauceChoice)
{
    if(sauceChoice == "")
        this->sidesChoice = 'N';
    else
        this->sidesChoice = 'Y';
}
        
void Meal::setSauceElement(std::string sauceElement)
{
    this->sidesElement = sauceElement;
}

std::string Meal::getMealType()
{
    return this->mealType;
}

std::string Meal::getMainElement()
{
    return this->mainElement;
}


std::string Meal::getMainPrepStrategy()
{
    return this->mainPrepStrategy;
}
        
char Meal::getSideChoice()
{
    return this->sidesChoice;
}

std::string Meal::getSidePrepStrategy()
{
    return this->sidePrepStrategy;
}

std::string Meal::getSidesElement()
{
    return this->sidesElement;
}

char Meal::getSauceChoice()
{
    return this->sauceChoice;
}

std::string Meal::getSauceElement()
{
    return this->sauceElement;
}

#endif