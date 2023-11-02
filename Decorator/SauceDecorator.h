#ifndef SAUCEDECORATOR_H
#define SAUCEDECORATOR_H

#include <iostream>

#include "MainOrder.h"

class SauceDecorator : public MainOrder{

    public:
        SauceDecorator(BasicOrder*);

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
            std::string type;

};

#endif