#include "ProteinDecorator.h"

ProteinDecorator::ProteinDecorator(BasicOrder *bo) : MainOrder(bo)
{
    type = "protein";
    if (MainOrder::MainOrder::basicOrder->dish == "Steak")
    {
        MainOrder::MainOrder::basicOrder->cost = 100.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 30.0;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Fish")
    {
        MainOrder::MainOrder::basicOrder->cost = 70.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 20.0;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Chicken")
    {
        MainOrder::MainOrder::basicOrder->cost = 80.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 25.0;
    }
    else if (MainOrder::MainOrder::basicOrder->dish == "Vegan")
    {
        MainOrder::MainOrder::basicOrder->cost = 50.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 25.0;
    }
}

std::string ProteinDecorator::print(){
    std::string s = "Dish: " + MainOrder::basicOrder->dish + "\nOf type: " + type +  "\nMade by: " + MainOrder::basicOrder->type + " type\nBy: " + MainOrder::basicOrder->strategy +
                    " strategy\nCost: R" + std::to_string(MainOrder::basicOrder->cost) + "\nTime to prepare: " + std::to_string(MainOrder::basicOrder->timeToPrep);
        return s;

}

double ProteinDecorator::getCost(){
    return MainOrder::basicOrder->cost;
}

double ProteinDecorator::getTimeToPrep(){
    return MainOrder::basicOrder->timeToPrep;
}

std::string ProteinDecorator::getDish(){
    return MainOrder::basicOrder->dish;
}

std::string ProteinDecorator::getStrategy(){
    return MainOrder::basicOrder->strategy;
}

std::string ProteinDecorator::getType(){
    return MainOrder::basicOrder->type;
}

void ProteinDecorator::setCost(double c){
    MainOrder::basicOrder->cost = c;
}

void ProteinDecorator::setTimeToPrep(double t){
    MainOrder::basicOrder->timeToPrep = t;
}

void ProteinDecorator::setDish(std::string d){
    MainOrder::basicOrder->dish = d;
}

void ProteinDecorator::setStrategy(std::string s){
    MainOrder::basicOrder->strategy = s;
}

void ProteinDecorator::setType(std::string c){
    MainOrder::basicOrder->type = c;
}
