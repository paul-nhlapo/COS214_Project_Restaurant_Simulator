#ifndef MAINORDER_H
#define MAINORDER_H

#include "SimpleOrder.h"

class MainOrder : public Order
{
    public:
        MainOrder(std::string mainElement, std::string cookingMethod, std::string side, std::string sauce);
        std::string getOrderType();
};

#endif