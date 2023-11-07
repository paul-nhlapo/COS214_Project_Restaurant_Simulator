#pragma once
#include "Command.h"
#include <iostream>
#include "Chef.h"
#include "ConcreteChefCreator.h"
#include "DessertChef.h"
#include "HeadChef.h"
#include "MainChef.h"
#include "StarterChef.h"
#include "Kitchen.h"

using namespace std;

class concreteCommand : public Command
{
private:
    Floor *floor;
    customerFactory *cf;
    OrderFactory *of;
    Kitchen *kitchen;
    ChefCreator *headChefCreator;
    ChefCreator *starterChefCreator;
    ChefCreator *mainChefCreator;
    ChefCreator *dessertChefCreator;

    HeadChef *headChef;
    StarterChef *starterChef;
    MainChef *mainChef;
    DessertChef *dessertChef;

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
