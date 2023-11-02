#include "BasicOrder.h"

BasicOrder::BasicOrder(std::string d, std::string s, std::string ch){
    dish = d;
    strategy = s;
    chef = ch;
    cost = 0.1;
    timeToPrep = 0.1;

    if(chef == "starter"){
        cost = 30.0;
        timeToPrep = 5.0;
    }
    else if(chef == "dessert"){
        cost = 60.0;
        timeToPrep = 10.0;
    }
}

BasicOrder::~BasicOrder(){

}


std::string BasicOrder::print(){
    std::string s = "Dish: " + dish + "\nMade by: " + chef + "\nBy: " + strategy + 
                    " strategy\nCost: R" + std::to_string(cost) + "\nTime to prepare: " + std::to_string(timeToPrep);
}


double BasicOrder::getCost(){
    return cost;
}

double BasicOrder::getTimeToPrep(){
    return timeToPrep;
}

std::string BasicOrder::getDish(){
    return dish;
}

std::string BasicOrder::getStrategy(){
    return strategy;
}

std::string BasicOrder::getChef(){
    return chef;
}


void BasicOrder::setCost(double c){
    cost = c;
}

void BasicOrder::setTimeToPrep(double t){
    timeToPrep = t;
}

void BasicOrder::setDish(std::string d){
    dish = d;
}

void BasicOrder::setStrategy(std::string s){
    strategy = s;
}

void BasicOrder::setChef(std::string c){
    chef = c;
}
