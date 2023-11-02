#ifndef PROTEINDECORATOR_H
#define PROTEINDECORATOR_H

#include <iostream>

#include "MainOrder.h"

class ProteinDecorator : public MainOrder{

    public:
        ProteinDecorator(BasicOrder*);
        ~ProteinDecorator();

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