#ifndef STARTERORDERBUILDER_CPP
#define STARTERORDERBUILDER_CPP

#include "StarterOrderBuilder.h"
#include "Order.h"

StarterOrderBuilder::StarterOrderBuilder()
{
    order = new Order_();
}

StarterOrderBuilder::~StarterOrderBuilder()
{
    // delete order;
}

void StarterOrderBuilder::setOrderType(int menuNumber)
{
    if (menuNumber == 1)
    {
        order->menuChoice = "Starter";
        order->price += 50.0;
    }
    else if (menuNumber == 2)
    {
        order->menuChoice = "Main";
        order->price += 100.0;
    }
    else
    {
        order->menuChoice = "Dessert";
        order->price += 75.0;
    }
}

void StarterOrderBuilder::setMainElement(int mainElement)
{
    order->mainElement = mainElement;
}

void StarterOrderBuilder::setMainElementPrepStrategy(int mainElementPrepStrategy)
{
    order->mainPrepStrategy = mainElementPrepStrategy;
}

void StarterOrderBuilder::setSideChoice(char sideChoice)
{
    order->sidesChoice = sideChoice;
}

void StarterOrderBuilder::setSideElement(int side)
{
    order->sidesElement = side;
}

void StarterOrderBuilder::setSidePrepStrategy(int sidePrepStrategy)
{
    order->sidePrepStrategy = sidePrepStrategy;
}

void StarterOrderBuilder::setSauceChoice(char sauceChoice)
{
    order->sauceChoice = sauceChoice;
}

void StarterOrderBuilder::setSauceElement(int sauce)
{
    order->sauceElement = sauce;
}

Order_ *StarterOrderBuilder::getOrder()
{
    return this->order;
}

#endif
