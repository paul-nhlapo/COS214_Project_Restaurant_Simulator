#ifndef MAINORDERBUILDER_CPP
#define MAINORDERBUILDER_CPP

#include "MainOrderBuilder.h"
#include "Order.h"

MainOrderBuilder::MainOrderBuilder() : OrderBuilder()
{
    order = new Order_();
}

MainOrderBuilder::~MainOrderBuilder()
{
    // delete order;
}

void MainOrderBuilder::setOrderType(int menuNumber)
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

void MainOrderBuilder::setMainElement(int mainElement)
{
    order->mainElement = mainElement;
}

void MainOrderBuilder::setMainElementPrepStrategy(int mainElementPrepStrategy)
{
    order->mainPrepStrategy = mainElementPrepStrategy;
}

void MainOrderBuilder::setSideChoice(char sideChoice)
{
    order->sidesChoice = sideChoice;
}

void MainOrderBuilder::setSideElement(int side)
{
    order->sidesElement = side;
}

void MainOrderBuilder::setSidePrepStrategy(int sidePrepStrategy)
{
    order->sidePrepStrategy = sidePrepStrategy;
}

void MainOrderBuilder::setSauceChoice(char sauceChoice)
{
    order->sauceChoice = sauceChoice;
}

void MainOrderBuilder::setSauceElement(int sauce)
{
    order->sauceElement = sauce;
}

Order_ *MainOrderBuilder::getOrder()
{
    return this->order;
}

#endif