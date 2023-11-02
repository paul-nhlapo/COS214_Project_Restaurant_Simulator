/*
    Head Chef Implementation file
*/
#ifndef HEADCHEF_CPP
#define HEADCHEF_CPP

#include "HeadChef.h"

HeadChef::HeadChef(std::string name) : Chef(name)
{
    this->chefType = "Head Chef";
}

void HeadChef::receiveOrder()
{

}

void HeadChef::sendOrder()
{

}

std::string HeadChef::getChefType()
{
    return this->chefType;
}

void HeadChef::prepareMeal(std::string mealType)
{
    nextChef->prepareMeal(mealType);
    
}

void HeadChef::setNextChef(Chef* nextChef)
{
    std::cout << this->getChefType() << " passing meal on" << std::endl;
    this->nextChef = nextChef;
}


/*
void HeadChef::addOrderToQueue(Order* order)                        //Main uses this to add new orders to relevant queue
{
    if(order->getMealType == "Starter")
    {
        starterQueue.push(order);                                   //Need to see what order is defined as
    }

    else if(order->getMealType() == "Main")
    {
        mainQueue.push(order);
    }

    else
    {
        dessertQueue.push(order);
    }
}


//Relevant Chef pops his queue

Order* HeadChef::popStarterQueue()
{
    if(!starterQueue.empty())
        starterQueue.pop();

    else
    {
        std::cout << "Queue is empty" << std::endl;
        return NULL;
    }
}

Order* HeadChef::popMainQueue()
{
    if(!mainQueue.empty())
        mainQueue.pop();

    else
    {
        std::cout << "Queue is empty" << std::endl;
        return NULL;
    }
}  

Order* HeadChef::popDessertQueue()
{
    if(!dessertQueue.empty())
        dessertQueue.pop();

    else
    {
        std::cout << "Queue is empty" << std::endl;
        return NULL;
    }
}  
*/
#endif