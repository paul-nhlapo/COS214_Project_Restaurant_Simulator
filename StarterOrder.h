#ifndef STARTERORDER_H
#define STARTERORDER_H

#include "SimpleOrder.h"

class StarterOrder : public Order
{
    public:
        StarterOrder(std::string mainElement, std::string cookingMethod, std::string side, std::string sauce);
        std::string getOrderType();
};

#endif