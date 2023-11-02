#include "SideDecorator.h"

SideDecorator::SideDecorator(BasicOrder* bo) : MainOrder(bo){
    type = "side";
    if(MainOrder::MainOrder::basicOrder->dish == "chips"){
        MainOrder::MainOrder::basicOrder->cost = 22.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 10.0;
    }
    else if(MainOrder::MainOrder::basicOrder->dish == "rice"){
        MainOrder::MainOrder::basicOrder->cost = 20.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 12.0;
    }
    else if(MainOrder::MainOrder::basicOrder->dish == "salad"){
        MainOrder::MainOrder::basicOrder->cost = 25.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 7.5;
    }
}

SideDecorator::~SideDecorator(){

}


std::string SideDecorator::print(){
    std::string s = "Dish: " + MainOrder::basicOrder->dish + " " + type +  "\nMade by: " + MainOrder::basicOrder->chef + "\nBy: " + MainOrder::basicOrder->strategy + 
                    " strategy\nCost: R" + std::toString(MainOrder::basicOrder->cost) + "\nTime to prepare: " + std::toString(MainOrder::basicOrder->timeToPrep);
}


double SideDecorator::getCost(){
    return MainOrder::basicOrder->cost;
}

double SideDecorator::getTimeToPrep(){
    return MainOrder::basicOrder->timeToPrep;
}

std::string SideDecorator::getDish(){
    return MainOrder::basicOrder->dish;
}

std::string SideDecorator::getStrategy(){
    return MainOrder::basicOrder->strategy;
}

std::string SideDecorator::getChef(){
    return MainOrder::basicOrder->chef;
}


void SideDecorator::setCost(double c){
    MainOrder::basicOrder->cost = c;
}

void SideDecorator::setTimeToPrep(double t){
    MainOrder::basicOrder->timeToPrep = t;
}

void SideDecorator::setDish(std::string d){
    MainOrder::basicOrder->dish = d;
}

void SideDecorator::setStrategy(std::string s){
    MainOrder::basicOrder->strategy = s;
}

void SideDecorator::setChef(std::string c){
    MainOrder::basicOrder->chef = c;
}
