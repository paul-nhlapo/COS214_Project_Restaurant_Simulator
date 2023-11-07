/*
    Dessert Chef Implementation file
*/
#ifndef DESSERTCHEF_CPP
#define DESSERTCHEF_CPP

#include "DessertChef.h"
#include "MealProduct.h"
#include "CookingStrategy.h"

DessertChef::DessertChef(std::string name, Kitchen *kitchen) : Chef(name, kitchen)
{
    this->chefType = "Dessert Course Chef";
}

void DessertChef::receiveOrder()
{
}

void DessertChef::sendOrder()
{
}

void DessertChef::sendMeal(Meal *meal)
{
    headChef->receiveMeal(meal);
}

std::string DessertChef::getChefType()
{
    return this->chefType;
}

void DessertChef::setHeadChef(HeadChef *headChef)
{
    this->headChef = headChef;
}

void DessertChef::prepareMeal(Order_ *order)
{
    if (order->getMenuChoice() == "Dessert")
    {
        this->changeChefState();
        std::cout << "Dessert chef is preparing" << order->getMainElement() << std::endl;

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
        else if (order->getMainPrepStrategy() == "Cold Dessert")
            this->cookingStrategy = new ColdDessert();
        else if (order->getMainPrepStrategy() == "Warm Dessert")
            this->cookingStrategy = new HotDessert();
        else
        {
            std::cout << "Invalid main cooking method. Cannot prepare meal." << std::endl;
            return;
        }

        if (order->getSidePrepStrategy() == "Grilled")
            this->sideStrategy = new Grill();
        else if (order->getSidePrepStrategy() == "Fried")
            this->sideStrategy = new Fry();
        else if (order->getSidePrepStrategy() == "Baked")
            this->sideStrategy = new Bake();
        else if (order->getSidePrepStrategy() == "Boiled")
            this->sideStrategy = new Boil();
        else if (order->getSidePrepStrategy() == "Sushi")
            this->sideStrategy = new Sushi();
        else if (order->getSidePrepStrategy() == "Saute")
            this->sideStrategy = new Saute();
        else if (order->getSidePrepStrategy() == "Simmered")
            this->sideStrategy = new Simmer();
        else if (order->getSidePrepStrategy() == "Salad")
            this->sideStrategy = new Salad();
        else if (order->getSidePrepStrategy() == "No Cook")
            this->sideStrategy = new NoCook();
        else
        {
            std::cout << "No side selected." << std::endl;
            this->sideStrategy = nullptr;
            // return;
        }

        // std::cout << order->getMainPrepStrategy() <<" is prep strat " << order->getMenuChoice()<< std::endl;

        // Builder
        MealBuilder *mealBuilder = new MealBuilder();

        mealBuilder->setMealType(order->getMenuChoice()); // Set Meal Type

        mealBuilder->setMainElement(order->getMainElement());                                             // Set Main Element
        mealBuilder->setMainElementPrepStrategy(cookingStrategy->cookMeal(order->getMainPrepStrategy())); // Set Main Cook Strat
        mealBuilder->setSideChoice(order->getSidesElement());                                             // Set Side Choice
        mealBuilder->setSideElement(order->getSidesElement());
        mealBuilder->setTableNO(order->tableNO);

        if (this->sideStrategy != nullptr)
        {                                                                                                  // Set Side Element
            mealBuilder->setSideElementPrepStrategy(sideStrategy->cookMeal(order->getSidePrepStrategy())); // Set Side Cook Strat
        }
        else
            mealBuilder->setSideElementPrepStrategy("No side");

        mealBuilder->setSauceChoice(order->getSauceElement());  // Set Sauce Choice
        mealBuilder->setSauceElement(order->getSauceElement()); // Set Sauce Element

        Meal *meal = mealBuilder->getMeal(); // Return Meal
        // set the table no.

        // meal->printMeal();

        // std::cout << "\n\nmain el" << meal->getMainElement() << "--";
        // std::cout << "\nside element " << meal->getSidesElement() << "---";
        // std::cout << "\nmainprep strate " << meal->getMainPrepStrategy() << "---";
        // std::cout << "\nsauce el " << meal->getSauceElement() << "---";
        // std::cout << "\nmeal type " << meal->getMealType() << "---";

        sendMeal(meal);
    }

    else
    {
        std::cout << this->getChefType() << " passing this order on" << std::endl;
        nextChef->prepareMeal(order);
    }
}

void DessertChef::setNextChef(Chef *nextChef)
{
    this->nextChef = nextChef;
}

Chef *DessertChef::getNextChef()
{
    return nextChef;
}

void DessertChef::receiveNotification(Staff *senderChef)
{
}

#endif