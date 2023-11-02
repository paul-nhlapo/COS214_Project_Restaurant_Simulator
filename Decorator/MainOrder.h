#ifndef MAINORDER_H
#define MAINORDER_H

#include <iostream>

#include "Order.h"
#include "BasicOrder.h"

class MainOrder : public Order{

    public:
        MainOrder(BasicOrder*);

        std::string print();

        double getCost();
        double getTimeToPrep();
        std::string getDish();
        std::string getStrategy();
        std::string getChef();

        void setCost(double);
        void setTimeToPrep(double);
        void setDish(std::string);
        void setStrategy(std::string);
        void setChef(std::string);

        protected:
            BasicOrder* basicOrder;

};

#endif