/*
    Main Chef Implementation file
*/
#ifndef MAINCHEF_CPP
#define MAINCHEF_CPP

#include "MainChef.h"
#include "MealProduct.h"
#include "CookingStrategy.h"

MainChef::MainChef(std::string name, Kitchen *kitchen) : Chef(name, kitchen)
{
    this->chefType = "Main Course Chef";
}

void MainChef::receiveOrder()
{
}

void MainChef::sendOrder()
{
}

void MainChef::sendMeal(Meal *meal)
{
    headChef->receiveMeal(meal);
}

std::string MainChef::getChefType()
{
    return this->chefType;
}

void MainChef::setHeadChef(HeadChef *headChef)
{
    this->headChef = headChef;
}

void MainChef::prepareMeal(Order_ *order)
{
    if (order->getMenuChoice() == "Main")
    {
        this->changeChefState();
        // std::cout << this->getChefType() <<" is preparing this meal" << std::endl;

        // Strategies
        if (order->getMainPrepStrategy() == "Grilled")
            this->cookingStrategy = new Grill();
        else if (order->getMainPrepStrategy() == "Fried")
            this->cookingStrategy = new Fry();
        else if (order->getMainPrepStrategy() == "Baked")
            this->cookingStrategy = new Bake();
        else if (order->getMainPrepStrategy() == "Boiled")
            this->cookingStrategy = new Boil();
        else if (order->getMainPrepStrategy() == "Sushi")
            this->cookingStrategy = new Sushi();
        else if (order->getMainPrepStrategy() == "Saute")
            this->cookingStrategy = new Saute();
        else if (order->getMainPrepStrategy() == "Simmered")
            this->cookingStrategy = new Simmer();
        else if (order->getMainPrepStrategy() == "Salad")
            this->cookingStrategy = new Salad();
        else if (order->getMainPrepStrategy() == "No Cook")
            this->cookingStrategy = new NoCook();
        else
        {
            std::cout << "Invalid cooking method. Cannot prepare meal." << std::endl;
            return;
        }

        if (order->getSidePrepStrategy() == "Grilled")
            this->cookingStrategy = new Grill();
        else if (order->getSidePrepStrategy() == "Fried")
            this->cookingStrategy = new Fry();
        else if (order->getSidePrepStrategy() == "Baked")
            this->cookingStrategy = new Bake();
        else if (order->getSidePrepStrategy() == "Boiled")
            this->cookingStrategy = new Boil();
        else if (order->getSidePrepStrategy() == "Sushi")
            this->cookingStrategy = new Sushi();
        else if (order->getSidePrepStrategy() == "Saute")
            this->cookingStrategy = new Saute();
        else if (order->getSidePrepStrategy() == "Simmered")
            this->cookingStrategy = new Simmer();
        else if (order->getSidePrepStrategy() == "Salad")
            this->cookingStrategy = new Salad();
        else if (order->getSidePrepStrategy() == "No Cook")
            this->cookingStrategy = new NoCook();
        else
        {
            std::cout << "Invalid cooking method. Cannot prepare meal." << std::endl;
            return;
        }

        // Builder
        MealBuilder *mealBuilder = new MealBuilder();

        mealBuilder->setMealType(order->getMenuChoice()); // Set Meal Type

        mealBuilder->setMainElement(order->getMainElement());                                             // Set Main Element
        mealBuilder->setMainElementPrepStrategy(cookingStrategy->cookMeal(order->getMainPrepStrategy())); // Set Main Cook Strat

        mealBuilder->setSideChoice(order->getSidesElement());                                             // Set Side Choice
        mealBuilder->setSideElement(order->getSidesElement());                                            // Set Side Element
        mealBuilder->setSideElementPrepStrategy(cookingStrategy->cookMeal(order->getSidePrepStrategy())); // Set Side Cook Strat

        mealBuilder->setSauceChoice(order->getSauceElement());  // Set Sauce Choice
        mealBuilder->setSauceElement(order->getSauceElement()); // Set Sauce Element

        Meal *meal = mealBuilder->getMeal(); // Return Meal
        // set the table no.

        // meal->printMeal();

        sendMeal(meal);
    }

    else
    {
        std::cout << this->getChefType() << " passing this order on" << std::endl;
        nextChef->prepareMeal(order);
    }
}

void MainChef::setNextChef(Chef *nextChef)
{
    this->nextChef = nextChef;
}

void MainChef::receiveNotification(Staff *senderChef)
{
}

#endif