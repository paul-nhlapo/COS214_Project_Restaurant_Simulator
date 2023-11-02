#include "MainOrder.h"

MainOrder::MainOrder(BasicOrder* bo) : basicOrder(bo){
}

MainOrder::~MainOrder(){

}

std::string MainOrder::print(){
    std::string s = "Dish: " + basicOrder->dish + "\nMade by: " + basicOrder->chef + "\nBy: " + basicOrder->strategy + 
                    " strategy\nCost: R" + std::toString(basicOrder->cost) + "\nTime to prepare: " + std::toString(basicOrder->timeToPrep);
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
