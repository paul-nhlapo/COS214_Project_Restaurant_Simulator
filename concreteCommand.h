#pragma once
#include "Command.h"
#include <iostream>
using namespace std;

class concreteCommand : public Command
{
private:
    maitreD *md;
    Floor *floor;
    customerFactory *cf;

public:
    concreteCommand(maitreD *md, Floor *f, customerFactory *cf);
    ~concreteCommand();
    Customer *produceCustomer(char group);
    void seatCustomer(Customer *c);
    void seatMultipleCustomers(int x, int y, Customer *c);
    char getGroupID();
    char setGroupID();
    pair<int, int> reserveGroupTable();
};
