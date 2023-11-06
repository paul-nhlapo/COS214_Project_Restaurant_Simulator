#pragma once

#include <iostream>

#include "MainOrder.h"

class StarterDecorator : public MainOrder
{

public:
    StarterDecorator(BasicOrder *);

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
