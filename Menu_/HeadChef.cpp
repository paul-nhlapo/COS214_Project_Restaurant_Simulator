/*
    Head Chef Implementation file
*/
#ifndef HEADCHEF_CPP
#define HEADCHEF_CPP

#include "HeadChef.h"
#include "MealProduct.h"
#include <vector>

HeadChef::HeadChef(std::string name, Kitchen *kitchen) : Chef(name, kitchen)
{
    this->chefType = "Head Chef";
    starterMeals = new std::vector<Meal*>();
}

void HeadChef::receiveMeal(Meal *meal)
{      
    if (meal->getMealType() == "Starter")
    {
        std::cout << "recmeal2 " << meal->getMealType() << " " << meal->getMainElement() << std::endl;
        //std::cout << "\n ss" << starterMeals.size();
        starterMeals->push_back(meal);
        //std::cout << "\n" << starterMeals.size();
        //kitchen->notifyMealReady();
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

Chef* HeadChef::getNextChef(){
    return nextChef;
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
        // starterQueue.push(order); // Need to see what order is defined as
        // after an order is enqueued he needs to send it along chain after checking if chef is free.
        // i think its fine because each chef will start off as free
        // not fine because there might be duplicats. one being made and one in queue
        if(nextChef->getCurrentState() == "Free"){
            prepareMeal(order);
        }
        else{
            starterQueue.push(order); 
        }
        
    }

    else if (order->getMenuChoice() == "Main")
    {
        if(nextChef->getNextChef()->getCurrentState() == "Free"){
            prepareMeal(order);
        }
        else{
            mainQueue.push(order); 
        }
    }

    else if (order->getMenuChoice() == "Dessert")
    {
        if(nextChef->getNextChef()->getNextChef()->getCurrentState() == "Free"){
            prepareMeal(order);
        }
        else{
            dessertQueue.push(order); 
        }
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