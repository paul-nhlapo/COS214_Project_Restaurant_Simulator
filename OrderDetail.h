#pragma once

#include <iostream>

#include "Order.h"

class OrderDetail : public Order_
{

public:
    OrderDetail(int tableID);
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
