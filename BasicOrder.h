#ifndef BASICORDER_H
#define BASICORDER_H

#include <iostream>

#include "Order.h"

class BasicOrder : public Order
{

public:
    BasicOrder(std::string, std::string, std::string);

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
};

#endif