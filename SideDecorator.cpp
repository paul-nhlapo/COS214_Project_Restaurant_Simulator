#include "SideDecorator.h"

SideDecorator::SideDecorator(BasicOrder *bo) : MainOrder(bo)
{
    type = "side";
    if (MainOrder::MainOrder::basicOrder->dish == "Chips")
    {
        MainOrder::MainOrder::basicOrder->cost = 22.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 10.0;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Rice")
    {
        MainOrder::MainOrder::basicOrder->cost = 20.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 12.0;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Salad")
    {
        MainOrder::MainOrder::basicOrder->cost = 25.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 7.5;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Coffee")
    {
        MainOrder::MainOrder::basicOrder->cost = 15.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 5.5;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Milkshake")
    {
        MainOrder::MainOrder::basicOrder->cost = 35.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 5.5;
    }
}

std::string SideDecorator::print()
{
    std::string s = "Dish: " + MainOrder::basicOrder->dish + " " + type + "\nMade by: " + MainOrder::basicOrder->type + " type\nBy: " + MainOrder::basicOrder->strategy +
                    " strategy\nCost: R" + std::to_string(MainOrder::basicOrder->cost) + "\nTime to prepare: " + std::to_string(MainOrder::basicOrder->timeToPrep);
    return s;
}

double SideDecorator::getCost()
{
    return MainOrder::basicOrder->cost;
}

double SideDecorator::getTimeToPrep()
{
    return MainOrder::basicOrder->timeToPrep;
}

std::string SideDecorator::getDish()
{
    return MainOrder::basicOrder->dish;
}

std::string SideDecorator::getStrategy()
{
    return MainOrder::basicOrder->strategy;
}

std::string SideDecorator::getType()
{
    return type;
}

void SideDecorator::setCost(double c)
{
    MainOrder::basicOrder->cost = c;
}

void SideDecorator::setTimeToPrep(double t)
{
    MainOrder::basicOrder->timeToPrep = t;
}

void SideDecorator::setDish(std::string d)
{
    MainOrder::basicOrder->dish = d;
}

void SideDecorator::setStrategy(std::string s)
{
    MainOrder::basicOrder->strategy = s;
}

void SideDecorator::setType(std::string c)
{
    MainOrder::basicOrder->type = c;
}
