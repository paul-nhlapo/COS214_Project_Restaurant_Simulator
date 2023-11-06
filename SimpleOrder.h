/*
    VERY BASIC ORDER CLASS
        - Gets added to relevant queue.
        - Gets popped if chef is avaialble
        - Passed along CoR 
*/
#ifndef SIMPLEORDER_H
#define SIMPLEORDER_H

#include <iostream>
#include <vector>

class Order
{
    public:
        Order();
        virtual ~Order() {};

        std::string getMainElement();
        std::string getSide();
        std::string getSauce();
        std::string getCookingMethod();
        virtual std::string getOrderType() = 0;
        double price;

    protected:
        std::string mainElement;
        std::string side;
        std::string sauce;
        std::string cookingMethod;
        std::string orderType;
};

#endif