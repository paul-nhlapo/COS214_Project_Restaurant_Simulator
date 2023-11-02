#include "ProteinDecorator.h"

ProteinDecorator::ProteinDecorator(BasicOrder* bo, std::string tp) : MainOrder(bo){
    type = tp;
}

ProteinDecorator::~ProteinDecorator(){

}


std::string ProteinDecorator::print(){
    std::string s = "Dish: " + basicOrder->dish + "\nMade by: " + basicOrder->chef + "\nBy: " + basicOrder->strategy + 
                    " strategy\nCost: R" + std::toString(basicOrder->cost) + "\nTime to prepare: " + std::toString(basicOrder->timeToPrep);
}


double ProteinDecorator::getCost(){
    return basicOrder->cost;
}

double ProteinDecorator::getTimeToPrep(){
    return basicOrder->timeToPrep;
}

std::string ProteinDecorator::getDish(){
    return basicOrder->dish;
}

std::string ProteinDecorator::getStrategy(){
    return basicOrder->strategy;
}

std::string ProteinDecorator::getChef(){
    return basicOrder->chef;
}


void ProteinDecorator::setCost(double c){
    basicOrder->cost = c;
}

void ProteinDecorator::setTimeToPrep(double t){
    basicOrder->timeToPrep = t;
}

void ProteinDecorator::setDish(std::string d){
    basicOrder->dish = d;
}

void ProteinDecorator::setStrategy(std::string s){
    basicOrder->strategy = s;
}

void ProteinDecorator::setChef(std::string c){
    basicOrder->chef = c;
}
