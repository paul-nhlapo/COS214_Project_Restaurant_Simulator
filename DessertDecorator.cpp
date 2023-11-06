#include "DessertDecorator.h"

DessertDecorator::DessertDecorator(BasicOrder *bo) : MainOrder(bo)
{
    type = "protein";
    if (MainOrder::MainOrder::basicOrder->dish == "Ice Cream")
    {
        MainOrder::MainOrder::basicOrder->cost = 40.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 15.0;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Cake")
    {
        MainOrder::MainOrder::basicOrder->cost = 95.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 10.0;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Chocolate Mousse")
    {
        MainOrder::MainOrder::basicOrder->cost = 65.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 10.0;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Malva Pudding")
    {
        MainOrder::MainOrder::basicOrder->cost = 65.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 10.0;
    }
}

std::string DessertDecorator::print()
{
    std::string s = "Dish: " + MainOrder::basicOrder->dish + "\nOf type: " + type + "\nMade by: " + MainOrder::basicOrder->type + " type\nBy: " + MainOrder::basicOrder->strategy +
                    " strategy\nCost: R" + std::to_string(MainOrder::basicOrder->cost) + "\nTime to prepare: " + std::to_string(MainOrder::basicOrder->timeToPrep);
    return s;
}

double DessertDecorator::getCost()
{
    return MainOrder::basicOrder->cost;
}

double DessertDecorator::getTimeToPrep()
{
    return MainOrder::basicOrder->timeToPrep;
}

std::string DessertDecorator::getDish()
{
    return MainOrder::basicOrder->dish;
}

std::string DessertDecorator::getStrategy()
{
    return MainOrder::basicOrder->strategy;
}

std::string DessertDecorator::getType()
{
    return MainOrder::basicOrder->type;
}

void DessertDecorator::setCost(double c)
{
    MainOrder::basicOrder->cost = c;
}

void DessertDecorator::setTimeToPrep(double t)
{
    MainOrder::basicOrder->timeToPrep = t;
}

void DessertDecorator::setDish(std::string d)
{
    MainOrder::basicOrder->dish = d;
}

void DessertDecorator::setStrategy(std::string s)
{
    MainOrder::basicOrder->strategy = s;
}

void DessertDecorator::setType(std::string c)
{
    MainOrder::basicOrder->type = c;
}
