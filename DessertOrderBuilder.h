#ifndef DESSERTORDERBUILDER_H
#define DESSERTORDERBUILDER_H

#include "OrderBuilder.h"

class DessertOrderBuilder : public OrderBuilder
{
public:
    DessertOrderBuilder();
    ~DessertOrderBuilder();

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