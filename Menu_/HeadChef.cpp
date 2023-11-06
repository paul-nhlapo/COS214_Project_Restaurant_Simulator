/*
    Head Chef Implementation file
*/
#ifndef HEADCHEF_CPP
#define HEADCHEF_CPP

#include "HeadChef.h"
#include "MealProduct.h"

HeadChef::HeadChef(std::string name, Kitchen *kitchen) : Chef(name, kitchen)
{
    this->chefType = "Head Chef";
}

void HeadChef::receiveMeal(Meal *meal)
{
    if (meal->getMealType() == "Starter")
    {
        starterMeals.push_back(meal);
        // kitchen->notifyMealReady();
    }

    else if (meal->getMealType() == "Main")
    {
        mainMeals.push_back(meal);
        // kitchen->notifyMealReady();
    }

    else
    {
        dessertMeals.push_back(meal);
        // kitchen->notifyMealReady();
    }
}

void HeadChef::sendOrder()
{
}

std::string HeadChef::getChefType()
{
    return this->chefType;
}

void HeadChef::prepareMeal(Order_ *order)
{
    std::cout << this->getChefType() << " passing meal on" << std::endl;
    nextChef->prepareMeal(order);
}

void HeadChef::setNextChef(Chef *nextChef)
{
    this->nextChef = nextChef;
}

void HeadChef::receiveNotification(Chef *senderChef)
{
    if (senderChef->getChefType() == "Starter Course Chef")
    {
        if (this->starterQueue.empty())
            return;

        else if (senderChef->getCurrentState() == "Free")
        {
            // Pop Main course order from queue and pass down chain
            this->prepareMeal(popStarterQueue());
        }
    }

    else if (senderChef->getChefType() == "Main Course Chef")
    {
        if (this->mainQueue.empty())
            return;

        else if (senderChef->getCurrentState() == "Free")
        {
            // Pop Main course order from queue and pass down chain
            this->prepareMeal(popMainQueue());
        }
    }

    else if (senderChef->getChefType() == "Dessert Course Chef")
    {
        if (this->dessertQueue.empty())
            return;

        else if (senderChef->getCurrentState() == "Free")
        {
            // Pop Main course order from queue and pass down chain
            this->prepareMeal(popDessertQueue());
        }
    }
}

void HeadChef::addOrderToQueue(Order_ *order) // Main uses this to add new orders to relevant queue
{
    if (order->getMenuChoice() == "Starter")
    {
        starterQueue.push(order); // Need to see what order is defined as
        // after an order is enqueued he needs to send it along chain after checking if chef is free.
        std::vector<Staff*> list = this->kitchen.getListOfStaff();
    }

    else if (order->getMenuChoice() == "Main")
    {
        mainQueue.push(order);
    }

    else if (order->getMenuChoice() == "Dessert")
    {
        dessertQueue.push(order);
    }

    else
        std::cout << "Not a valid order type" << std::endl;
}

// Relevant Chef pops his queue

Order_ *HeadChef::popStarterQueue()
{
    if (!starterQueue.empty())
        starterQueue.pop();

    else
    {
        std::cout << "Queue is empty" << std::endl;
        return NULL;
    }
}

Order_ *HeadChef::popMainQueue()
{
    if (!mainQueue.empty())
        mainQueue.pop();

    else
    {
        std::cout << "Queue is empty" << std::endl;
        return NULL;
    }
}

Order_ *HeadChef::popDessertQueue()
{
    if (!dessertQueue.empty())
        dessertQueue.pop();

    else
    {
        std::cout << "Queue is empty" << std::endl;
        return NULL;
    }
}

void HeadChef::receiveNotification(Staff *SenderChef)
{
}

#endif