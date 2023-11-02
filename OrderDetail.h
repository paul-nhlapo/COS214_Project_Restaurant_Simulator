#pragma once
#include <string>
#include <iostream>
#include "Order.h"
using namespace std;

class OrderDetail : public Order
{
public:
    OrderDetail();
    OrderDetail(int ID);
    void addInfo(string x);
    void addDetail(int ID);
};