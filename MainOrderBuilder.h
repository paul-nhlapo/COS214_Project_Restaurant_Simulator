#ifndef MAINORDERBUILDER_H
#define MAINORDERBUILDER_H

#include "OrderBuilder.h"
// #include "Order.h"

class MainOrderBuilder : public OrderBuilder
{
public:
    MainOrderBuilder();
    ~MainOrderBuilder();

    void setOrderType(int menuNumber);

    void setMainElement(int mainElement);
    void setMainElementPrepStrategy(int mainElementPrepStrategy);

    void setSideChoice(char sideChoice);
    void setSideElement(int side);
    void setSidePrepStrategy(int sidePrepStrategy);

    void setSauceChoice(char sauceChoice);
    void setSauceElement(int sauce);

    Order_ *getOrder();
};

#endif