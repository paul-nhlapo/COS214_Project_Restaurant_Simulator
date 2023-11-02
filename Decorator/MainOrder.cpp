#include "MainOrder.h"

MainOrder::MainOrder(BasicOrder* bo) : basicOrder(bo){
}



std::string MainOrder::print(){
    std::string s = "Dish: " + basicOrder->dish + "\nMade by: " + basicOrder->chef + " chef\nBy: " + basicOrder->strategy + 
                    " strategy\nCost: R" + std::to_string(basicOrder->cost) + "\nTime to prepare: " + std::to_string(basicOrder->timeToPrep);
    return s;
}


double MainOrder::getCost(){
    return basicOrder->cost;
}

double MainOrder::getTimeToPrep(){
    return basicOrder->timeToPrep;
}

std::string MainOrder::getDish(){
    return basicOrder->dish;
}

std::string MainOrder::getStrategy(){
    return basicOrder->strategy;
}

std::string MainOrder::getChef(){
    return basicOrder->chef;
}


void MainOrder::setCost(double c){
    basicOrder->cost = c;
}

void MainOrder::setTimeToPrep(double t){
    basicOrder->timeToPrep = t;
}

void MainOrder::setDish(std::string d){
    basicOrder->dish = d;
}

void MainOrder::setStrategy(std::string s){
    basicOrder->strategy = s;
}

void MainOrder::setChef(std::string c){
    basicOrder->chef = c;
}
