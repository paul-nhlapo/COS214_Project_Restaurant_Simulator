#ifndef STARTERORDERBUILDER_H
#define STARTERORDERBUILDER_H

#include "OrderBuilder.h"

class StarterOrderBuilder : public OrderBuilder
{
    public:
        StarterOrderBuilder();
        ~StarterOrderBuilder();
        
        void setOrderType(int menuNumber);

        void setMainElement(int mainElement);
        void setMainElementPrepStrategy(int mainElementPrepStrategy);

        void setSideChoice(char sideChoice);
        void setSideElement(int side);
        void setSidePrepStrategy(int sidePrepStrategy);

        void setSauceChoice(char sauceChoice);
        void setSauceElement(int sauce);

        Order_* getOrder();
};

#endif