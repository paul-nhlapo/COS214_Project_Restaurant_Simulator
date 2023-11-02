#ifndef BASICORDER_H
#define BASICORDER_H

#include <iostream>

#include "Order.h"

class BasicOrder : public Order{

    public:
        BasicOrder(std::string, std::string, std::string);

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

        public:
            double cost;
            double timeToPrep;
            std::string dish;
            std::string strategy;
            std::string chef;

};

#endif