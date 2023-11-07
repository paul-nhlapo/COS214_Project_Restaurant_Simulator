#include "StarterDecorator.h"

StarterDecorator::StarterDecorator(BasicOrder *bo) : MainOrder(bo)
{
    type = "protein";
    if (MainOrder::MainOrder::basicOrder->dish == "Bread Roll")
    {
        MainOrder::MainOrder::basicOrder->cost = 25.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 10.0;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Soup")
    {
        MainOrder::MainOrder::basicOrder->cost = 50.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 20.0;
    }
}

std::string StarterDecorator::print()
{
    std::string s = "Dish: " + MainOrder::basicOrder->dish + "\nOf type: " + type + "\nMade by: " + MainOrder::basicOrder->type + " type\nBy: " + MainOrder::basicOrder->strategy +
                    " strategy\nCost: R" + std::to_string(MainOrder::basicOrder->cost) + "\nTime to prepare: " + std::to_string(MainOrder::basicOrder->timeToPrep);
    return s;
}

double StarterDecorator::getCost()
{
    return MainOrder::basicOrder->cost;
}

double StarterDecorator::getTimeToPrep()
{
    return MainOrder::basicOrder->timeToPrep;
}

std::string StarterDecorator::getDish()
{
    return MainOrder::basicOrder->dish;
}

std::string StarterDecorator::getStrategy()
{
    return MainOrder::basicOrder->strategy;
}

std::string StarterDecorator::getType()
{
    return MainOrder::basicOrder->type;
}

void StarterDecorator::setCost(double c)
{
    MainOrder::basicOrder->cost = c;
}

void StarterDecorator::setTimeToPrep(double t)
{
    MainOrder::basicOrder->timeToPrep = t;
}

void StarterDecorator::setDish(std::string d)
{
    MainOrder::basicOrder->dish = d;
}

void StarterDecorator::setStrategy(std::string s)
{
    MainOrder::basicOrder->strategy = s;
}

void StarterDecorator::setType(std::string c)
{
    MainOrder::basicOrder->type = c;
}
