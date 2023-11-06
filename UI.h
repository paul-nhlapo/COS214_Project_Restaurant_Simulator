#pragma once
#include "Command.h"
#include "concreteCommand.h"
#include "customerFactory.h"
#include "Customer.h"
#include "Factory.h"
#include "Staff.h"
#include "maitreD.h"
#include "Waiter.h"
#include "Floor.h"
#include "OrderFactory.h"
using namespace std;

class UI
{
private:
    concreteCommand *c1;
    Floor *mainFloor;

public:
    UI(concreteCommand *c, Floor* f);
    ~UI();
    void addCustomer();
    void order();
    void additionLoop();
};
