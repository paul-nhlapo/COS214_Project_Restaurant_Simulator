#ifndef PROTEINDECORATOR_H
#define PROTEINDECORATOR_H

#include <iostream>

#include "MainOrder.h"

class ProteinDecorator : public MainOrder{

    public:
        ProteinDecorator(BasicOrder*);

        std::string print();

        double getCost();
        double getTimeToPrep();
        std::string getDish();
        std::string getStrategy();
        std::string getType();

        void setCost(double);
        void setTimeToPrep(double);
        void setDish(std::string);
        void setStrategy(std::string);
        void setType(std::string);

        protected:
            std::string type;

};

#endif