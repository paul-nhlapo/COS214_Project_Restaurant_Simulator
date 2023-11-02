#include "VegDecorator.h"

VegDecorator::VegDecorator(BasicOrder* bo) : MainOrder(bo){
    type = "veg";
    if(MainOrder::MainOrder::basicOrder->dish == "middle east"){
        MainOrder::MainOrder::basicOrder->cost = 100.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 30.0;
    }
    else if(MainOrder::MainOrder::basicOrder->dish == "mediterranean"){
        MainOrder::MainOrder::basicOrder->cost = 70.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 20.0;
    }
    else if(MainOrder::MainOrder::basicOrder->dish == "south african"){
        MainOrder::MainOrder::basicOrder->cost = 80.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 25.0;
    }
}

VegDecorator::~VegDecorator(){

}


std::string VegDecorator::print(){
    std::string s = "Dish: " + MainOrder::basicOrder->dish + " " + type +  "\nMade by: " + MainOrder::basicOrder->chef + "\nBy: " + MainOrder::basicOrder->strategy + 
                    " strategy\nCost: R" + std::toString(MainOrder::basicOrder->cost) + "\nTime to prepare: " + std::toString(MainOrder::basicOrder->timeToPrep);
}


double VegDecorator::getCost(){
    return MainOrder::basicOrder->cost;
}

double VegDecorator::getTimeToPrep(){
    return MainOrder::basicOrder->timeToPrep;
}

std::string VegDecorator::getDish(){
    return MainOrder::basicOrder->dish;
}

std::string VegDecorator::getStrategy(){
    return MainOrder::basicOrder->strategy;
}

std::string VegDecorator::getChef(){
    return MainOrder::basicOrder->chef;
}


void VegDecorator::setCost(double c){
    MainOrder::basicOrder->cost = c;
}

void VegDecorator::setTimeToPrep(double t){
    MainOrder::basicOrder->timeToPrep = t;
}

void VegDecorator::setDish(std::string d){
    MainOrder::basicOrder->dish = d;
}

void VegDecorator::setStrategy(std::string s){
    MainOrder::basicOrder->strategy = s;
}

void VegDecorator::setChef(std::string c){
    MainOrder::basicOrder->chef = c;
}
