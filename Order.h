#pragma once
#include <string>
#include <iostream>
using namespace std;

class Order
{
public:
    string type;
    string name;
    int ID;
    Order();
    Order(int ID);
    virtual void addInfo(string x) = 0;
    virtual void addDetail(int ID) = 0;
};