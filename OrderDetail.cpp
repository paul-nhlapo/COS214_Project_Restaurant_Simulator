#include "OrderDetail.h"

OrderDetail::OrderDetail(int tableID)
{
    this->tableID = tableID;
    this->oD = true;
}

std::string OrderDetail::print()
{
    std::string s = "Dish: " + dish + "\nMade by: " + type + " type\nBy: " + strategy +
                    " strategy\nCost: R" + std::to_string(cost) + "\nTime to prepare: " + std::to_string(timeToPrep);
    return s;
}

double OrderDetail::getCost()
{
    return 0.0;
}

double OrderDetail::getTimeToPrep()
{
    return 0.0;
}

std::string OrderDetail::getDish()
{
    return "";
}

std::string OrderDetail::getStrategy()
{
    return "";
}

std::string OrderDetail::getType()
{
    return "";
}

void OrderDetail::setCost(double c)
{
    return;
}

void OrderDetail::setTimeToPrep(double t)
{
    return;
}

void OrderDetail::setDish(std::string d)
{
    return;
}

void OrderDetail::setStrategy(std::string s)
{
    return;
}

void OrderDetail::setType(std::string c)
{
    return;
}