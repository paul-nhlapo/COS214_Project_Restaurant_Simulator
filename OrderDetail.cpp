#include "OrderDetail.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

OrderDetail::OrderDetail() : Order()
{
    this->type = "Detail";
}

OrderDetail::OrderDetail(int ID) : Order(ID)
{
    this->type = "Detail";
}

void OrderDetail::addDetail(int ID)
{
    this->ID = ID;
}

void OrderDetail::addInfo(string x)
{
    return;
}