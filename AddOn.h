#pragma once
#include <string>
#include <iostream>
#include "Order.h"
using namespace std;

class AddOn : public Order
{
public:
    Order *nextItem;
    AddOn();
    AddOn(Order *nextItem);
    void addInfo(string x) = 0;
    void addDetail(int ID) = 0;
    void setNextItem(Order *nI);
    AddOn *sp();
};