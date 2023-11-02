#include "Order.h"
#include <string>
#include <vector>
using namespace std;

Order::Order()
{
    this->ID = -1;
    this->name = "";
    this->type = "";
}

Order::Order(int ID)
{
    this->ID = ID;
    this->name = "";
    this->type = "";
}