#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H

#include <iostream>

#include "Order.h"

class OrderBuilder
{
public:
    void virtual setOrderType(int menuNumber) = 0;

    void virtual setMainElement(int mainElement) = 0;
    void virtual setMainElementPrepStrategy(int mainElementPrepStrategy) = 0;

    void virtual setSideChoice(char sideChoice) = 0;
    void virtual setSideElement(int side) = 0;
    void virtual setSidePrepStrategy(int sidePrepStrategy) = 0;

    void virtual setSauceChoice(char sauceChoice) = 0;
    void virtual setSauceElement(int sauce) = 0;

    virtual Order_ *getOrder() = 0;

protected:
    Order_ *order;
};
#endif