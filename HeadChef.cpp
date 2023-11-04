/*
    Head Chef Implementation file
*/
#ifndef HEADCHEF_CPP
#define HEADCHEF_CPP

#include "HeadChef.h"

HeadChef::HeadChef(std::string name, Kitchen* kitchen) : Chef(name, kitchen)
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

/*
void HeadChef::prepareMeal(std::string mealType)
{
    nextChef->prepareMeal(mealType);
}
*/

void HeadChef::prepareMeal(Order* order)
{
    std::cout << this->getChefType() << " passing meal on" << std::endl;
    nextChef->prepareMeal(order);
}

void HeadChef::setNextChef(Chef* nextChef)
{
    this->nextChef = nextChef;
}

/*
void HeadChef::receiveNotification(Chef* senderChef)
{
    if(senderChef->getChefType() == "Starter Course Chef")
    {
        if(senderChef->getCurrentState() == "Free")
        {
            //Pop Main course order from queue and pass down chain
            this->prepareMeal("DEFINE QUEUE POPPING METHOD PROPERLY");
        }
    }

    else if(senderChef->getChefType() == "Main Course Chef")
    {
        if(senderChef->getCurrentState() == "Free")
        {
            //Pop Main course order from queue and pass down chain
            this->prepareMeal("DEFINE QUEUE POPPING METHOD PROPERLY");
        }
    }

    else if(senderChef->getChefType() == "Dessert Course Chef")
    {
        if(senderChef->getCurrentState() == "Free")
        {
            //Pop Main course order from queue and pass down chain
            this->prepareMeal("DEFINE QUEUE POPPING METHOD PROPERLY");
        }
    }
}
*/

void HeadChef::receiveNotification(Chef* senderChef)
{
    if(senderChef->getChefType() == "Starter Course Chef")
    {
        if(this->starterQueue.empty())
            return;

        else if(senderChef->getCurrentState() == "Free")
        {
            //Pop Main course order from queue and pass down chain
            this->prepareMeal(popStarterQueue());
        }
    }

    else if(senderChef->getChefType() == "Main Course Chef")
    {
        if(this->mainQueue.empty())
            return;
        
        else if(senderChef->getCurrentState() == "Free")
        {
            //Pop Main course order from queue and pass down chain
            this->prepareMeal(popMainQueue());
        }
    }

    else if(senderChef->getChefType() == "Dessert Course Chef")
    {
        if(this->dessertQueue.empty())
            return;
        
        else if(senderChef->getCurrentState() == "Free")
        {
            //Pop Main course order from queue and pass down chain
            this->prepareMeal(popDessertQueue());
        }
    }
}



void HeadChef::addOrderToQueue(Order* order)                        //Main uses this to add new orders to relevant queue
{
    if(order->getOrderType() == "Starter")
    {
        starterQueue.push(order);                                   //Need to see what order is defined as
    }

    else if(order->getOrderType() == "Main")
    {
        mainQueue.push(order);
    }

    else if(order->getOrderType() == "Dessert")
    {
        dessertQueue.push(order);
    }

    else
        std::cout << "Not a valid order type" << std::endl;
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
  
#endif