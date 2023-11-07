#pragma once
#include "Command.h"
#include <iostream>
using namespace std;

class concreteCommand : public Command
{
private:
    Floor *floor;
    customerFactory *cf;
    OrderFactory *of;

public:
    maitreD *md;

    concreteCommand(maitreD *md, Floor *f, customerFactory *cf, OrderFactory *of);
    ~concreteCommand();
    Customer *produceCustomer(char group);
    void seatCustomer(Customer *c);
    void seatMultipleCustomers(int x, int y, Customer *c);
    char getGroupID();
    char setGroupID();
    pair<int, int> reserveGroupTable();
    void startOrdering();
    bool verify();
};
