#ifndef DESSERTORDER_H
#define DESSERTORDER_H

#include "SimpleOrder.h"

class DessertOrder : public Order
{
    public:
        DessertOrder(std::string mainElement, std::string cookingMethod, std::string side, std::string sauce);
        std::string getOrderType();
};

#endif