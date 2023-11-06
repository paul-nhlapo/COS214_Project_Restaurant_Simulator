#ifndef DESSERTORDERBUILDER_CPP
#define DESSERTORDERBUILDER_CPP

#include "DessertOrderBuilder.h"
#include "Order.h"

DessertOrderBuilder::DessertOrderBuilder()
{
    order = new Order_();
}

DessertOrderBuilder::~DessertOrderBuilder()
{
    delete order;
}

void DessertOrderBuilder::setOrderType(int menuNumber)
{
    if(menuNumber == 1)
        order->menuChoice = "Starter";

    else if(menuNumber == 2)
        order->menuChoice = "Main";

    else
        order->menuChoice = "Dessert";       
        
}

void DessertOrderBuilder::setMainElement(int mainElement)
{
    order->mainElement = mainElement;
}

void DessertOrderBuilder::setMainElementPrepStrategy(int mainElementPrepStrategy)
{
    order->mainPrepStrategy = mainElementPrepStrategy;
}

void DessertOrderBuilder::setSideChoice(char sideChoice)
{
    order->sidesChoice = sideChoice;
}


void DessertOrderBuilder::setSideElement(int side)
{
    order->sidesElement = side;
}


void DessertOrderBuilder::setSidePrepStrategy(int sidePrepStrategy)
{
    order->sidePrepStrategy = sidePrepStrategy;
}

void DessertOrderBuilder::setSauceChoice(char sauceChoice)
{
    order->sauceChoice = sauceChoice;
}

void DessertOrderBuilder::setSauceElement(int sauce)
{
    order->sauceElement = sauce;
}

Order_* DessertOrderBuilder::getOrder()
{
    return this->order;
}

#endif