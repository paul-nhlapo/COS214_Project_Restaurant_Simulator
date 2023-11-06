#pragma once
#include "Factory.h"
#include "customerFactory.h"
#include "Customer.h"
#include "Staff.h"
#include "maitreD.h"
#include "Waiter.h"
#include "Floor.h"
#include "OrderFactory.h"
using namespace std;

class Command
{
private:
public:
    Command();
    virtual ~Command();
    virtual Customer *produceCustomer(char group) = 0;
    virtual void seatCustomer(Customer *c) = 0;
    virtual char getGroupID() = 0;
    virtual char setGroupID() = 0;
    virtual void startOrdering() = 0;
};
