#include <iostream>

#include "BasicOrder.h"
#include "MainOrder.h"
#include "Order.h"
#include "ProteinDecorator.h"
#include "SauceDecorator.h"
#include "SideDecorator.h"
#include "VegDecorator.h"

#include "BasicOrder.cpp"
#include "MainOrder.cpp"
#include "ProteinDecorator.cpp"
#include "SauceDecorator.cpp"
#include "SideDecorator.cpp"
#include "VegDecorator.cpp"


int main(){

    BasicOrder b1("soup" , "boil" , "starter");
    std::cout << b1.print();
    
}