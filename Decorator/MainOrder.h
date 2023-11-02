#ifndef MAINORDER_H
#define MAINORDER_H

#include <iostream>

#include "Order.h"
#include "BasicOrder.h"

class MainOrder : public Order{

    public:
        MainOrder(BasicOrder*);

        virtual std::string print();

        virtual double getCost();
        virtual double getTimeToPrep();
        virtual std::string getDish();
        virtual std::string getStrategy();
        virtual std::string getChef();

        virtual void setCost(double);
        virtual void setTimeToPrep(double);
        virtual void setDish(std::string);
        virtual void setStrategy(std::string);
        virtual void setChef(std::string);

        protected:
            BasicOrder* basicOrder;

};

#endif