#include "SauceDecorator.h"

SauceDecorator::SauceDecorator(BasicOrder* bo) : MainOrder(bo){
    type = "sauce";
    if(MainOrder::MainOrder::basicOrder->dish == "garlic"){
        MainOrder::MainOrder::basicOrder->cost = 10.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 5.0;
    }
    else if(MainOrder::MainOrder::basicOrder->dish == "lemon"){
        MainOrder::MainOrder::basicOrder->cost = 10.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 5.0;
    }
    else if(MainOrder::MainOrder::basicOrder->dish == "red wine"){
        MainOrder::MainOrder::basicOrder->cost = 15.0;
        MainOrder::MainOrder::basicOrder->timeToPrep = 6.5;
    }
}

SauceDecorator::~SauceDecorator(){

}


std::string SauceDecorator::print(){
    std::string s = "Dish: " + MainOrder::basicOrder->dish + " " + type +  "\nMade by: " + MainOrder::basicOrder->chef + "\nBy: " + MainOrder::basicOrder->strategy + 
                    " strategy\nCost: R" + std::to_string(MainOrder::basicOrder->cost) + "\nTime to prepare: " + std::to_string(MainOrder::basicOrder->timeToPrep);
}


double SauceDecorator::getCost(){
    return MainOrder::basicOrder->cost;
}

double SauceDecorator::getTimeToPrep(){
    return MainOrder::basicOrder->timeToPrep;
}

std::string SauceDecorator::getDish(){
    return MainOrder::basicOrder->dish;
}

std::string SauceDecorator::getStrategy(){
    return MainOrder::basicOrder->strategy;
}

std::string SauceDecorator::getChef(){
    return MainOrder::basicOrder->chef;
}


void SauceDecorator::setCost(double c){
    MainOrder::basicOrder->cost = c;
}

void SauceDecorator::setTimeToPrep(double t){
    MainOrder::basicOrder->timeToPrep = t;
}

void SauceDecorator::setDish(std::string d){
    MainOrder::basicOrder->dish = d;
}

void SauceDecorator::setStrategy(std::string s){
    MainOrder::basicOrder->strategy = s;
}

void SauceDecorator::setChef(std::string c){
    MainOrder::basicOrder->chef = c;
}
