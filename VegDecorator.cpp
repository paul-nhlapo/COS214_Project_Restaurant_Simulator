#include "VegDecorator.h"

VegDecorator::VegDecorator(BasicOrder *bo) : MainOrder(bo)
{
    type = "Veg";
    if (MainOrder::MainOrder::basicOrder->dish == "Middle East")
    {
        MainOrder::MainOrder::basicOrder->cost = 100.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 30.0;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Mediterranean")
    {
        MainOrder::MainOrder::basicOrder->cost = 70.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 20.0;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "South African")
    {
        MainOrder::MainOrder::basicOrder->cost = 80.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 25.0;
    }
}

std::string VegDecorator::print()
{
    std::string s = "Dish: " + MainOrder::basicOrder->dish + " " + type + "\nMade by: " + MainOrder::basicOrder->type + " type\nBy: " + MainOrder::basicOrder->strategy +
                    " strategy\nCost: R" + std::to_string(MainOrder::basicOrder->cost) + "\nTime to prepare: " + std::to_string(MainOrder::basicOrder->timeToPrep);
    return s;
}

double VegDecorator::getCost()
{
    return MainOrder::basicOrder->cost;
}

double VegDecorator::getTimeToPrep()
{
    return MainOrder::basicOrder->timeToPrep;
}

std::string VegDecorator::getDish()
{
    return MainOrder::basicOrder->dish;
}

std::string VegDecorator::getStrategy()
{
    return MainOrder::basicOrder->strategy;
}

std::string VegDecorator::getType()
{
    return type;
}

void VegDecorator::setCost(double c)
{
    MainOrder::basicOrder->cost = c;
}

void VegDecorator::setTimeToPrep(double t)
{
    MainOrder::basicOrder->timeToPrep = t;
}

void VegDecorator::setDish(std::string d)
{
    MainOrder::basicOrder->dish = d;
}

void VegDecorator::setStrategy(std::string s)
{
    MainOrder::basicOrder->strategy = s;
}

void VegDecorator::setType(std::string c)
{
    MainOrder::basicOrder->type = c;
}
