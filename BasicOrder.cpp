#include "BasicOrder.h"

BasicOrder::BasicOrder(std::string d, std::string s, std::string ch)
{
    dish = d;
    strategy = s;
    type = ch;
    cost = 0.1;
    timeToPrep = 0.1;
    this->oD = false;

    if (type == "starter")
    {
        cost = 30.0;
        timeToPrep = 5.0;
    }
    else if (type == "dessert")
    {
        cost = 60.0;
        timeToPrep = 10.0;
    }
}

std::string BasicOrder::print()
{
    std::string s = "Dish: " + dish + "\nMade by: " + type + " type\nBy: " + strategy +
                    " strategy\nCost: R" + std::to_string(cost) + "\nTime to prepare: " + std::to_string(timeToPrep);
    return s;
}

double BasicOrder::getCost()
{
    return cost;
}

double BasicOrder::getTimeToPrep()
{
    return timeToPrep;
}

std::string BasicOrder::getDish()
{
    return dish;
}

std::string BasicOrder::getStrategy()
{
    return strategy;
}

std::string BasicOrder::getType()
{
    return type;
}

void BasicOrder::setCost(double c)
{
    cost = c;
}

void BasicOrder::setTimeToPrep(double t)
{
    timeToPrep = t;
}

void BasicOrder::setDish(std::string d)
{
    dish = d;
}

void BasicOrder::setStrategy(std::string s)
{
    strategy = s;
}

void BasicOrder::setType(std::string c)
{
    type = c;
}
