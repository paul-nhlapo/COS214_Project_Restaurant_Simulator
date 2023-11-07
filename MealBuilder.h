#ifndef MEALBUILDER_H
#define MEALBUILDER_H

#include <iostream>

#include "MealProduct.h"
#include "CookingStrategy.h"

class MealBuilder
{
public:
public:
    MealBuilder();
    virtual ~MealBuilder();

    void virtual setMealType(std::string mealType);

    void virtual setMainElement(std::string mainElement);
    void virtual setMainElementPrepStrategy(std::string mainElementPrepStrategy);

    void virtual setSideChoice(std::string sideChoice);
    void virtual setSideElement(std::string side);
    void virtual setSideElementPrepStrategy(std::string sidePrepStrategy);

    void virtual setSauceChoice(std::string sauceChoice);
    void virtual setSauceElement(std::string sauce);

    void virtual setTableNO(int i);

    virtual Meal *getMeal();

protected:
    Meal *meal;
};
#endif