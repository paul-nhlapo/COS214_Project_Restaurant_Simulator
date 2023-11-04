/*
    Main Chef Implementation file
*/
#ifndef MAINCHEF_CPP
#define MAINCHEF_CPP

#include "MainChef.h"

MainChef::MainChef(std::string name, Kitchen* kitchen) : Chef(name, kitchen)
{
    this->chefType = "Main Course Chef";
}

void MainChef::receiveOrder()
{

}

void MainChef::sendOrder()
{

}

std::string MainChef::getChefType()
{
    return this->chefType;
}

/*
void MainChef::prepareMeal(std::string mealType)
{
    if(mealType == "Main")
    {
        std::cout << "Main Chef is preparing this meal";
    }

    else
    {
        std::cout << this->getChefType() << " passing meal on" << std::endl;
        nextChef->prepareMeal(mealType);
    }
}
*/

void MainChef::prepareMeal(Order* order)
{
    if(order->getOrderType() == "Main")
    {
        std::cout << this->getChefType() <<" is preparing this meal" << std::endl;
    }

    else
    {
        std::cout << this->getChefType() << " passing this order on" << std::endl;
        nextChef->prepareMeal(order);
    }
}

void MainChef::setNextChef(Chef* nextChef)
{
    this->nextChef = nextChef;
}



#endif